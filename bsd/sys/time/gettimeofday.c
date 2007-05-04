#ifndef BSD_SYS_TIME_GETTIMEOFDAY_C
#define BSD_SYS_TIME_GETTIMEOFDAY_C

#include <bsd/sys/time/gettimeofday.h>

#if WANT_GETTIMEOFDAY_WIN32

#include <sys/time.h>	/* struct timeval */
#include <sys/timeb.h>	/* struct _timeb _ftime() */


#if LIBNOSTD_STATIC
static
#endif
int gettimeofday(struct timeval *tv, struct timezone *tz) {
	struct _timeb tb;

	if (tv == 0)
		return -1;

	_ftime(&tb);

	tv->tv_sec	= tb.time;
	tv->tv_usec	= (int)tb.millitm * 1000;

	return 0;
} /* gettimeofday() */

#endif /* WANT_GETTIMEOFDAY_WIN32 */

#endif /* BSD_SYS_TIME_GETTIMEOFDAY_C */
