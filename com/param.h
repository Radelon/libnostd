#ifndef LIBCOM_COM_PARAM_H
#define LIBCOM_COM_PARAM_H

#include <stddef.h>	/* size_t offsetof */

#include <limits.h>	/* CHAR_BIT */


#if !defined arraylen
#define arraylen(a, b)	(sizeof (a) / sizeof (a)[0])
#endif


/*
 * TODO: Detect any compilers, if any, which provide offsetof() as a
 * built-in.
 */
#if !defined offsetof && !defined HAVE_OFFSETOF
#define offsetof(t, m)	((size_t) & ((t *)0)->m)
#endif


/*
 * TODO: More comprehensive compiler detection.
 *
 * GNU C:	__alignof__
 * TinyC:	__alignof__, __alignof
 * MSVC:	__alignof
 * IBMC:	__alignof__
 */
#if !defined alignof && !defined HAVE_ALIGNOF

#if defined __GNUC__
#define alignof(t)	__alignof__(t)

#elif defined __TINYC__
#define alignof(t)	__alignof__(t)

#elif defined _MSC_VER
#define alignof(t)	__alignof(t)

#elif defined __IBMC__
#define alignof(t)	__alignof__(t)

#else
#define alignof(t)	offsetof(struct { char c; t x; }, x)
#endif

#endif /* !defined alignof && !defined HAVE_ALIGNOF */


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


#if !defined howmany
#define howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

#if !defined roundup
#define roundup(x, y)	((((x) + ((y) - 1)) / (y)) * (y))
#endif

#if !defined powerof2
#define powerof2(x)	((((x) - 1) & (x)) == 0)
#endif


#if !defined MIN
#define MIN(a, b)	(((a) < (b))? (a) : (b))
#endif

#if !defined MAX
#define MAX(a, b)	(((a) > (b))? (a) : (b))
#endif


#endif /* LIBCOM_COM_PARAM_H */
