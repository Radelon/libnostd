#ifndef BSD_ERR_H
#define BSD_ERR_H

#ifndef HAVE_ERR_H
#if defined(_WIN32)
#define HAVE_ERR_H	0
#else
#define HAVE_ERR_H	1
#endif
#endif


#if HAVE_ERR_H

#include_next <err.h>

#else

#include <stdio.h>	/* vsnprintf(3) */
#include <stdarg.h>	/* va_list va_start va_end */
#include <stdlib.h>	/* exit(3) */

#include <string.h>	/* strerror(3) */

#include <win32/windows/GetLastError.h>
#include <win32/windows/SetLastError.h>


#ifndef BSD_ERR_BUFSIZ
#define BSD_ERR_BUFSIZ	512
#endif


static inline void xverr(int retcode, const char *fmt, va_list args) {
	int error	= GetLastError();
	char buf[BSD_ERR_BUFSIZ];

	if (0 < vsnprintf(buf, sizeof buf, fmt, args))
		(void)fprintf(stderr, "%s: %s\n", buf, strerror(error));
	else
		(void)fprintf(stderr, "(%s): %s\n", strerror(GetLastError()), strerror(error));

	exit(retcode);
} /* xverr() */


static inline void xerr(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	verr(fmt, ap);

	/* NOT REACHED */
} /* xerr() */


static inline void xverrx(int retcode, const char *fmt, va_list args) {
	int error	= GetLastError();
	char buf[BSD_ERR_BUFSIZ];

	if (0 < vsnprintf(buf, sizeof buf, fmt, args))
		(void)fprintf(stderr, "%s\n", buf);
	else
		(void)fprintf(stderr, "(%s): %s\n", strerror(GetLastError()), strerror(error));

	exit(retcode);
} /* xverrx() */


static inline void xerrx(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	xverrx(fmt, ap);

	/* NOT REACHED */
} /* xerrx() */


static inline void xvwarn(const char *fmt, va_list args) {
	int error	= GetLastError();
	char buf[BSD_ERR_BUFSIZ];

	if (0 < vsnprintf(buf, sizeof buf, fmt, args))
		(void)fprintf(stderr, "%s: %s\n", buf, strerror(error));
	else
		(void)fprintf(stderr, "(%s): %s\n", strerror(GetLastError()), strerror(error));

	fflush(stderr);

	SetLastError(error);

	return /* void */;
} /* xvwarn() */


static inline void xwarn(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	xvwarn(fmt, ap);

	va_end(ap);

	return /* void */;
} /* xwarn() */


static inline void xvwarnx(const char *fmt, va_list args) {
	int error	= GetLastError();
	char buf[BSD_ERR_BUFSIZ];

	if (0 < vsnprintf(buf, sizeof buf, fmt, args))
		(void)fprintf(stderr, "%s\n", buf);
	else
		(void)fprintf(stderr, "(%s): %s\n", strerror(GetLastError()), strerror(error));

	fflush(stderr);

	SetLastError(errno);

	return /* void */;
} /* xvwarnx() */


static inline void xwarnx(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	xvwarnx(fmt, ap);

	va_end(ap);

	return /* void */;
} /* xwarnx() */


#define verr(...)	xverr(__VA_ARGS__)
#define verrx(...)	xverrx(__VA_ARGS__)
#define err(...)	xerr(__VA_ARGS__)
#define errx(...)	xerrx(__VA_ARGS__)

#define vwarn(...)	xvwarn(__VA_ARGS__)
#define vwarnx(...)	xvwarnx(__VA_ARGS__)
#define warn(...)	xwarn(__VA_ARGS__)
#define warnx(...)	xwarnx(__VA_ARGS__)


#endif /* HAVE_ERR_H */

#endif /* !BSD_ERR_H */
