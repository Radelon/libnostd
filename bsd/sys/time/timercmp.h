#ifndef BSD_SYS_TIME_TIMERCMP_H
#define BSD_SYS_TIME_TIMERCMP_H

#include <sys/time.h>	/* struct timeval timercmp */

#if !defined timercmp
#define timercmp(a, b, cmp)				\
	(((a)->tv_sec == (b)->tv_sec)			\
		? (a)->tv_usec cmp (b)->tv_usec		\
		: (a)->tv_sec cmp (b)->tv_sec)
#endif

#endif /* BSD_SYS_TIME_TIMERCMP_H */
