#ifndef BSD_SYS_PARAM_POWEROF2_H
#define BSD_SYS_PARAM_POWEROF2_H

#include <bsd/sys/param/counting.h>

#if !defined powerof2
#define powerof2(x)	((((x) - 1) & (x)) == 0)
#endif

#endif /* !BSD_SYS_PARAM_POWEROF2_H */
