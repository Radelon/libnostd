#ifndef STRING_STRLCAT_H
#define STRING_STRLCAT_H


#if HAVE_STRLCAT || __OpenBSD__ || __NetBSD__ || __FreeBSD__
#define WANT_STRLCAT_BSD	1
#else
#define WANT_STRLCAT_C99	1
#endif


#if WANT_STRLCAT_BSD

#include <string.h>	/* strlcat(3) */

#endif /* WANT_STRLCAT_BSD */


#if WANT_STRLCAT_C99

#include <stddef.h>	/* size_t */

#if LIBNOSTD_STATIC
static
#endif
size_t strlcat(char *, const char *, size_t);

#endif /* WANT_STRLCAT_C99 */


#if LIBNOSTD_STATIC
#include <string/strlcat.c>
#endif


#endif /* STRING_STRLCAT_H */
