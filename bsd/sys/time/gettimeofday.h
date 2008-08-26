#ifndef BSD_SYS_TIME_GETTIMEOFDAY_H
#define BSD_SYS_TIME_GETTIMEOFDAY_H


#if _WIN32
#include <sys/time.h>
#else
#include_next <sys/time.h>
#endif


#ifndef HAVE_GETTIMEOFDAY
#if _WIN32
#define HAVE_GETTIMEOFDAY	0
#else
#define HAVE_GETTIMEOFDAY	1
#endif
#endif 


#if !HAVE_GETTIMEOFDAY

struct timezone;

#include <sys/timeb.h>	/* struct _timeb _ftime() */


static int gettimeofday(struct timeval *tv, struct timezone *tz) {
	struct _timeb tb;

	if (tv == 0)
		return -1;

	_ftime(&tb);

	tv->tv_sec	= tb.time;
	tv->tv_usec	= (int)tb.millitm * 1000;

	return 0;
} /* gettimeofday() */

#endif /* !HAVE_GETTIMEOFDAY */


#endif /* BSD_SYS_TIME_GETTIMEOFDAY_H */
