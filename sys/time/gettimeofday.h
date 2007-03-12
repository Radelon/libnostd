#ifndef SYS_TIME_GETTIMEOFDAY_H
#define SYS_TIME_GETTIMEOFDAY_H


#if HAVE_GETTIMEOFDAY
#define WANT_GETTIMEOFDAY_SUSv3
#elif _WIN32
#define WANT_GETTIMEOFDAY_WIN32
#else
#define WANT_GETTIMEOFDAY_SUSv3
#endif


#if WANT_GETTIMEOFDAY_SUSv3

#include <sys/time.h>	/* struct timeval gettimeofday(2) */

#endif /* WANT_GETTIMEOFDAY_SUSv3 */


#if WANT_GETTIMEOFDAY_WIN32

#include <sys/time.h>	/* struct timeval */

int gettimeofday(struct timeval *, struct timezone *);

#endif /* WANT_GETTIMEOFDAY_WIN32 */


#endif /* SYS_TIME_GETTIMEOFDAY_H */
