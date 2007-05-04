#ifndef BSD_SYS_PARAM_ISSET_H
#define BSD_SYS_PARAM_ISSET_H

#include <limits.h>	/* CHAR_BIT */

#include <bsd/sys/param/bitmap.h>

#if !defined isset
#define isset(a, i)	((a)[(i) / CHAR_BIT] & (1 << ((i) % CHAR_BIT)))
#endif

#endif /* !BSD_SYS_PARAM_ISSET_H */
