#ifndef BSD_SYS_PARAM_HOWMANY_H
#define BSD_SYS_PARAM_HOWMANY_H

#include <bsd/sys/param/counting.h>

#if !defined howmany
#define howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

#endif /* !BSD_SYS_PARAM_HOWMANY_H */
