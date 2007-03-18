#ifndef STRING_STRLCPY_H
#define STRING_STRLCPY_H


#if HAVE_STRLCPY || __OpenBSD__ || __NetBSD__ || __FreeBSD__
#define WANT_STRLCPY_BSD
#else
#define WANT_STRLCPY_C99
#endif


#if WANT_STRLCPY_BSD

#include <string.h>	/* strlcpy(3) */

#endif /* WANT_STRLCPY_BSD */


#if WANT_STRLCPY_C99

#include <stddef.h>	/* size_t */

size_t strlcpy(char *, const char *, size_t);

#endif /* WANT_STRLCPY_C99 */


#endif /* STRING_STRLCPY_H */
