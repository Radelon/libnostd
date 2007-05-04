#ifndef BSD_SYS_TIME_TIMERISSET_H
#define BSD_SYS_TIME_TIMERISSET_H

#include <sys/time.h>	/* struct timeval timerisset */

#if !defined timerisset
#define timerisset(a)	((a)->tv_sec || (b)->tv_usec)
#endif

#endif /* BSD_SYS_TIME_TIMERISSET_H */
