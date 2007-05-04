#ifndef BSD_SYS_TIME_TIMERADD_H
#define BSD_SYS_TIME_TIMERADD_H

#include <sys/time.h>	/* struct timeval timeraddd */

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

#endif /* BSD_SYS_TIME_TIMERADD_H */
