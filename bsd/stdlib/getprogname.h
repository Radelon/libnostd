#ifndef BSD_STDLIB_GETPROGNAME_H
#define BSD_STDLIB_GETPROGNAME_H

#ifndef HAVE_GETPROGNAME
#if defined __FreeBSD__ \
 || defined __NetBSD__  \
 || defined __APPLE__
#define HAVE_GETPROGNAME 1
#else
#define HAVE_GETPROGNAME 0
#endif
#endif


#if !HAVE_GETPROGNAME

#if __GLIBC__
#include <errno.h>	/* program_invocation_short_name */
#endif

#if _WIN32
#include <string.h>	/* strrchr(3) */
#endif


static inline const char *getprogname(void) {
#if __OpenBSD__
	extern const char *__progname;

	return __progname;
#elif __GLIBC__
#ifndef _GNU_SOURCE
	extern char *program_invocation_short_name;
#endif
	return program_invocation_short_name;
#elif _WIN32
	char *shortname, *progname = _pgmptr;

	return ((shortname = strrchr(progname, '\\')) || (shortname = strrchr(progname, '/')))? ++shortname : progname;
#else
	return 0;
#endif
} /* getprogname() */

#endif /* !HAVE_GETPROGNAME */


#endif /* BSD_STDLIB_GETPROGNAME_H */
