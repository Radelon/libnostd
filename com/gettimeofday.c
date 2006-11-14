#ifndef LIBCOM_COM_GETTIMEOFDAY_C
#define LIBCOM_COM_GETTIMEOFDAY_C

#include <com/config.h>		/* LIBCOM_SCOPE */

#include <sys/time.h>		/* struct timeval */

#include <com/gettimeofday.h>

#if _WIN32

#include <sys/timeb.h>

struct timezone;


LIBCOM_GETTIMEOFDAY_SCOPE int gettimeofday(struct timeval *tv, struct timezone *tz) {
	struct _timeb tb;

	if (tv == 0)
		return -1;

	_ftime(&tb);

	tv->tv_sec	= tb.time;
	tv->tv_usec	= (int)tb.millitm * 1000;

	return 0;
} /* gettimeofday() */

#endif /* _WIN32 */

#endif /* LIBCOM_COM_GETTIMEOFDAY_C */
