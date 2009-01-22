#ifndef GNU_STRING_STRNLEN_H
#define GNU_STRING_STRNLEN_H

#if !defined(HAVE_STRNLEN)
#if defined(strnlen)
#define HAVE_STRNLEN	1
#endif
#endif


#if !HAVE_STRNLEN
#include <stddef.h>	/* size_t */

#include <string.h>	/* strlen(3) */

#define strnlen(str, lim) xstrnlen(str, lim)

static inline size_t xstrnlen(const char *str, size_t lim) {
	size_t len	= strlen(str);

	return (lim < len)? lim : len;
} /* xstrnlen() */
#endif


#endif /* GNU_STRING_STRNLEN_H */
