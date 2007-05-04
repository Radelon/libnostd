#ifndef BSD_SYS_PARAM_MAX_H
#define BSD_SYS_PARAM_MAX_H

#include <bsd/sys/param/MINMAX.h>

#if !defined MAX
#define MAX(a, b)	(((a) > (b))? (a) : (b))
#endif

#endif /* !BSD_SYS_PARAM_MAX_H */
