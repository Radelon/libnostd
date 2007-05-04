#ifndef BSD_SYS_PARAM_ROUNDUP_H
#define BSD_SYS_PARAM_ROUNDUP_H

#include <bsd/sys/param/counting.h>

#if !defined roundup
#define roundup(x, y)	((((x) + ((y) - 1)) / (y)) * (y))
#endif

#endif /* !BSD_SYS_PARAM_ROUNDUP_H */
