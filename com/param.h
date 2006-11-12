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


/*
 * The PP_NARG macro returns the number of arguments that have been passed
 * to it.
 *
 * PP_NARG(A) -> 1
 * PP_NARG(A,B) -> 2
 * PP_NARG(A,B,C) -> 3
 * PP_NARG(A,B,C,D) -> 4
 * PP_NARG(A,B,C,D,E) -> 5 
 *
 * (Laurent Deniau, news:comp.std.c, Jan 16, 2006)
 */
#define PP_NARG(...)	PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...)	PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N( \
	_1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
	_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
	_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
	_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
	_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
	_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
	_61,_62,_63,N,...) N

#define PP_RSEQ_N() \
	63,62,61,60,                   \
	59,58,57,56,55,54,53,52,51,50, \
	49,48,47,46,45,44,43,42,41,40, \
	39,38,37,36,35,34,33,32,31,30, \
	29,28,27,26,25,24,23,22,21,20, \
	19,18,17,16,15,14,13,12,11,10, \
	9,8,7,6,5,4,3,2,1,0 

#endif /* LIBCOM_COM_PARAM_H */
