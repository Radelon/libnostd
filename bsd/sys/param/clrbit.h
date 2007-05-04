#ifndef BSD_SYS_PARAM_CLRBIT_H
#define BSD_SYS_PARAM_CLRBIT_H

#include <limits.h>	/* CHAR_BIT */

#include <bsd/sys/param/bitmap.h>

#if !defined clrbit
#define clrbit(a, i)	((a)[(i) / CHAR_BIT] &= ~(1 << ((i) % CHAR_BIT)))
#endif

#endif /* !BSD_SYS_PARAM_CLRBIT_H */
