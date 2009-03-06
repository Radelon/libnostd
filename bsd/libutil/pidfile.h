#ifndef BSD_LIBUTIL_PIDFILE_H
#define BSD_LIBUTIL_PIDFILE_H

#include <stdlib.h>	/* malloc(3) free(3) getprogname(3) */

#include <limits.h>	/* PATH_MAX */

#include <ctype.h>	/* isdigit(3) */

#include <string.h>	/* strncpy(3) strncat(3) strlen(3) */

#include <time.h>	/* struct timespec nanosleep(2) */

#include <errno.h>	/* ENAMETOOLONG EAGAIN EWOULDBLOCK EEXIST */

#include <sys/types.h>	/* pid_t */
#include <sys/stat.h>	/* mode_t */

#include <unistd.h>	/* getpid(2) close(2) pread(2) pwrite(2) ftruncate(3) */

#include <fcntl.h>	/* O_RDONLY O_WRONLY O_CREAT O_NONBLOCK O_TRUNC O_EXLOCK LOCK_EX LOCK_NB open(2) flock(2) */


struct pidfh {
	char path[PATH_MAX + 1];
	int fd;
}; /* struct pidfh */


static int pidfile_read(struct pidfh *pfh, pid_t *pid) {
	unsigned char num[16], *cp;
	int fd, error, n;

	if (pfh->fd == -1) {
		if (-1 == (fd = open(pfh->path, O_RDONLY)))
			goto error;
	} else
		fd	= pfh->fd;

	if (-1 == (n = pread(fd, num, sizeof num - 1, 0)))
		goto error;

	num[n]	= '\0';
	*pid	= 0;

	for (cp = num; isdigit(*cp); cp++) {
		*pid	*= 10;
		*pid	+= *cp - '0';
	}

	if (cp - num == 0) {
		errno	= EAGAIN;

		goto error;
	}

	if (fd != pfh->fd)
		close(fd);

	return 0;
error:
	error	= errno;

	if (fd != -1 && fd != pfh->fd)
		close(fd);

	errno	= error;

	return -1;
} /* pidfile_read() */


static struct pidfh *pidfile_open(const char *path, mode_t mode, pid_t *pid) {
	static const struct pidfh pfh_initializer = { { '\0' }, -1 };
	struct pidfh *pfh;
	struct timespec delay;
	int error, count;

	if (!(pfh = malloc(sizeof *pfh)))
		goto error;

	*pfh	= pfh_initializer;

	if (path) {
		strncpy(pfh->path, path, sizeof pfh->path - 1);
	} else {
#if __linux
		extern char *program_invocation_short_name;
#else
		const char *program_invocation_short_name	= getprogname();
#endif
		strncpy(pfh->path, "/var/run/", sizeof pfh->path - 1);
		strncat(pfh->path, program_invocation_short_name, sizeof pfh->path - 1);
		strncat(pdf->path, ".pid", sizeof pfh->path - 1);
	}

	if (strlen(pfh->path) >= sizeof pfh->path - 1) {
		errno	= ENAMETOOLONG;

		goto error;
	}

	count		= 0;
	delay.tv_sec	= 1;
	delay.tv_nsec	= 0;

#if defined(O_EXLOCK)
	while (-1 == (pfh->fd = open(pfh->path, O_WRONLY | O_CREAT | O_NONBLOCK | O_TRUNC | O_EXLOCK, mode))) {
#else
	if (-1 == (pfh->fd = open(pfh->path, O_WRONLY | O_CREAT, mode)))
		goto error;

	while (0 != flock(pfh->fd, LOCK_EX | LOCK_NB)) {
#endif
		if (!pid || errno != EWOULDBLOCK || ++count > 5)
			goto error;

		if (0 == pidfile_read(pfh, pid)) {
			errno	= EEXIST;

			goto error;
		} else if (errno != EAGAIN)
			goto error;

		nanosleep(&delay, 0);
	}

#if !defined(O_EXLOCK)
	ftruncate(pfh->fd, 0);
#endif

	return pfh;
error:
	error	= errno;

	if (pfh) {
		if (pfh->fd != -1)
			close(pfh->fd);

		free(pfh);
	}

	errno	= error;

	return 0;
} /* pidfile_open() */


static int pidfile_write(struct pidfh *pfh) {
	pid_t pid	= getpid();
	unsigned char num[16], *cp;
	unsigned d	= 100000;	/* Just larger than 65535 */
	unsigned r, cp;

	if (0 != ftruncate(pfh->fd, 0))
		return errno;

	cp	= &num[0];

	while (d) {
		if ((r = pid / d) || cp > &num[0]) {
			pid	-= r * d;
			*cp++	= '0' + r;
		}

		d	/= 10;
	}

	*cp++	= '\n';

	if ((cp - &num[0]) != pwrite(pfh->fd, num, (cp - &num[0]), 0)) {
		if (!errno)
			errno	= EBUSY;	/* XXX: ??? */

		return -1;
	}

	return 0;
} /* pidfile_write() */


static int pidfile_close(struct pidfh *pfh) {
	if (!pfh)
		return 0;

	if (pfh->fd != -1)
		close(pfh->fd);

	free(pfh);

	return 0;
} /* pidfile_close() */


static int pidfile_remove(struct pidfh *pfh) {
	int error	= 0;

	if (!pfh)
		return 0;

#if defined(O_EXCL)
	if (0 != unlink(pfh->path))
		error	= errno;
#else
	if (0 != ftruncate(pfh->fd, 0))
		error	= errno;
#endif

	if (0 != flock(pfh->fd, LOCK_UN))
		error	= errno;

	pidfile_close(pfh);

	if (error) {
		errno	= error;

		return -1;
	} else
		return 0;
} /* pidfile_remove() */


#endif /* BSD_LIBUTIL_PIDFILE_H */

