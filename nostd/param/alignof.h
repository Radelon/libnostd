#ifndef NOSTD_PARAM_ALIGNOF_H
#define NOSTD_PARAM_ALIGNOF_H

#include <stddef.h>	/* offsetof */


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


#endif /* NOSTD_PARAM_ALIGNOF_H */
