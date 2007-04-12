
#ifndef SYS_PARAM_BITMAP_H
#define SYS_PARAM_BITMAP_H


#if HAVE_SYS_PARAM_BITMAP
#define WANT_SYS_PARAM_BITMAP_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_BITMAP_WIN32	1
#else
#define WANT_SYS_PARAM_BITMAP_BSD	1
#endif


#if WANT_SYS_PARAM_BITMAP_BSD

#include <sys/param.h>	/* setbit clrbit isset isclr */

#endif /* WANT_SYS_PARAM_BITMAP_BSD */


#if WANT_SYS_PARAM_BITMAP_WIN32

#include <limits.h>	/* CHAR_BIT */

#if !defined setbit
#define setbit(a, i)	((a)[(i) / CHAR_BIT] |= 1 << ((i) % CHAR_BIT))
#endif

#if !defined clrbit
#define clrbit(a, i)	((a)[(i) / CHAR_BIT] &= ~(1 << ((i) % CHAR_BIT)))
#endif

#if !defined isset
#define isset(a, i)	((a)[(i) / CHAR_BIT] & (1 << ((i) % CHAR_BIT)))
#endif

#if !defined isclr
#define isclr(a, i)	(!isset((a), (i)))
#endif

#endif /* WANT_SYS_PARAM_BITMAP_WIN32 */


#endif /* SYS_PARAM_BITMAP_H */
