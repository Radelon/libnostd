#ifndef LIBCOM_COM_TIME_H
#define LIBCOM_COM_TIME_H

#include <sys/time.h>		/* struct timeval timerclear timerisset timeradd timersub timercmp */

#include <com/alloca.h>		/* alloca() */


/*
 * timerset: helper routine for setting/instantiating struct timeval objects.
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
#define timerset_(sec, usec, tvbuf, ...)	timerset(sec, usec, ((tvbuf == 0)? alloca(sizeof (struct timeval)) : tvbuf))
#endif

#if !defined timerset
#define timerset(sec, ...)	timerset_(sec, __VA_ARGS__, (struct timeval *)0)
#endif


#if !defined timerclear
#define timerclear(a)	((a)->tv_sec = (b)->tv_usec = 0)
#endif

#if !defined timerisset
#define timerisset(a)	((a)->tv_sec || (b)->tv_usec)
#endif

#if !defined timercmp
#define timercmp(a, b, cmp)				\
	(((a)->tv_sec == (b)->tv_sec)			\
		? (a)->tv_usec cmp (b)->tv_usec		\
		: (a)->tv_sec cmp (b)->tv_sec)
#endif

#if !defined timeradd
#define timeradd(a, b, r) do {					\
	(r)->tv_sec	= (a)->tv_sec + (b)->tv_sec;		\
	(r)->tv_usec	= (a)->tv_usec + (b)->tv_usec;		\
	if ((r)->tv_usec >= 1000000) {				\
		++(r)->tv_sec;					\
		(r)->tv_usec -= 1000000;			\
	}							\
} while (0)
#endif

#if !defined timersub
#define	timersub(a, b, r) do {					\
	(r)->tv_sec	= (a)->tv_sec - (b)->tv_sec;		\
	(r)->tv_usec	= (a)->tv_usec - (b)->tv_usec;		\
	if ((r)->tv_usec < 0) {					\
		--(r)->tv_sec;					\
		(r)->tv_usec += 1000000;			\
	}							\
} while (0)
#endif


#include <com/gettimeofday.h>


#endif /* LIBCOM_COM_TIME_H */
