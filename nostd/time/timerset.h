#ifndef NOSTD_PARAM_TIME_TIMERSET_H
#define NOSTD_PARAM_TIME_TIMERSET_H

#include <sys/time.h>	/* struct timeval */


/*
 * timerset: helper routine for setting/instantiating struct timeval "timer"
 * objects.
 *
 * TODO: Be smarter about alloca() use. Fallback to static (or thread-local)
 * object ring buffer.
 */
static struct timeval *timerset(long sec, long usec, struct timeval *tvp) {
	tvp->tv_sec	= sec;
	tvp->tv_usec	= usec;

	return tvp;
} /* timerset() */

#if !defined timerset_
#define timerset_(sec, usec, tvbuf, ...)	\
	timerset_(sec, usec, ((tvbuf == 0)? alloca(sizeof (struct timeval)) : tvbuf))
#endif

#if !defined timerset
#define timerset(sec, ...)	\
	timerset_(sec, __VA_ARGS__, (struct timeval *)0)
#endif


#endif /* NOSTD_PARAM_TIME_TIMERSET_H */
