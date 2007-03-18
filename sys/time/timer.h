#ifndef SYS_TIME_TIMER_H
#define SYS_TIME_TIMER_H

#include <sys/time.h>	/* struct timeval timerclear timerisset timeradd timersub timercmp */


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



#endif /* !SYS_TIME_TIMER_H */
