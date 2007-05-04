#ifndef BSD_SYS_TIME_GETTIMEOFDAY_H
#define BSD_SYS_TIME_GETTIMEOFDAY_H


#if HAVE_GETTIMEOFDAY
#define WANT_GETTIMEOFDAY_BSD	1
#elif _WIN32
#define WANT_GETTIMEOFDAY_WIN32	1
#else
#define WANT_GETTIMEOFDAY_BSD	1
#endif


#if WANT_GETTIMEOFDAY_BSD

#include <sys/time.h>	/* struct timeval gettimeofday(2) */

#endif /* WANT_GETTIMEOFDAY_BSD */


#if WANT_GETTIMEOFDAY_WIN32

#include <sys/time.h>	/* struct timeval */


struct timezone;

#if LIBNOSTD_STATIC
static
#endif
int gettimeofday(struct timeval *, struct timezone *);

#if LIBNOSTD_STATIC
#include <bsd/sys/time/gettimeofday.c>
#endif

#endif /* WANT_GETTIMEOFDAY_WIN32 */


#endif /* BSD_SYS_TIME_GETTIMEOFDAY_H */
