#ifndef BSD_SYS_TIME_TIMERCLEAR_H
#define BSD_SYS_TIME_TIMERCLEAR_H

#include <sys/time.h>	/* struct timeval timerclear */

#if !defined timerclear
#define timerclear(a)	((a)->tv_sec = (b)->tv_usec = 0)
#endif

#endif /* BSD_SYS_TIME_TIMERCLEAR_H */

