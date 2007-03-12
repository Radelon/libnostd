

#if WANT_GETTIMEOFDAY_WIN32

#ifndef HAVE_GETTIMEOFDAY_WIN32
#define HAVE_GETTIMEOFDAY_WIN32

#include <sys/time.h>	/* struct timeval */
#include <sys/timeb.h>	/* struct _timeb _ftime() */


int gettimeofday(struct timeval *tv, struct timezone *tz) {
	struct _timeb tb;

	if (tv == 0)
		return -1;

	_ftime(&tb);

	tv->tv_sec	= tb.time;
	tv->tv_usec	= (int)tb.millitm * 1000;

	return 0;
} /* gettimeofday() */


#endif /* HAVE_GETTIMEOFDAY_WIN32 */

#endif /* WANT_GETTIMEOFDAY_WIN32 */
