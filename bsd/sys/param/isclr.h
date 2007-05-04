#ifndef BSD_SYS_PARAM_ISCLR_H
#define BSD_SYS_PARAM_ISCLR_H

#include <limits.h>	/* CHAR_BIT */

#include <bsd/sys/param/bitmap.h>

#if !defined isclr
#define isclr(a, i)	(!isset((a), (i)))
#endif

#endif /* !BSD_SYS_PARAM_ISCLR_H */
