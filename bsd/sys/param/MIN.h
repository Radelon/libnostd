#ifndef BSD_SYS_PARAM_MIN_H
#define BSD_SYS_PARAM_MIN_H

#include <sys/param/MINMAX.h>

#if !defined MIN
#define MIN(a, b)	(((a) < (b))? (a) : (b))
#endif

#endif /* !BSD_SYS_PARAM_MIN_H */
