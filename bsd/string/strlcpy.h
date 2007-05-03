#ifndef BSD_STRING_STRLCPY_H
#define BSD_STRING_STRLCPY_H


#if HAVE_STRLCPY || __OpenBSD__ || __NetBSD__ || __FreeBSD__
#define WANT_STRLCPY_BSD	1
#else
#define WANT_STRLCPY_C99	1
#endif


#if WANT_STRLCPY_BSD

#include <string.h>	/* strlcpy(3) */

#endif /* WANT_STRLCPY_BSD */


#if WANT_STRLCPY_C99

#include <stddef.h>	/* size_t */

#if LIBNOSTD_STATIC
static
#endif
size_t strlcpy(char *, const char *, size_t);

#endif /* WANT_STRLCPY_C99 */


#if LIBNOSTD_STATIC
#include <bsd/string/strlcpy.c>
#endif


#endif /* BSD_STRING_STRLCPY_H */
