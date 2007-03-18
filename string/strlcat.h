#ifndef STRING_STRLCAT_H
#define STRING_STRLCAT_H


#if HAVE_STRLCAT || __OpenBSD__ || __NetBSD__ || __FreeBSD__
#define WANT_STRLCAT_BSD
#else
#define WANT_STRLCAT_C99
#endif


#if WANT_STRLCAT_BSD

#include <string.h>	/* strlcat(3) */

#endif /* WANT_STRLCAT_BSD */


#if WANT_STRLCAT_C99

#include <stddef.h>	/* size_t */

size_t strlcat(char *, const char *, size_t);

#endif /* WANT_STRLCAT_C99 */


#endif /* STRING_STRLCAT_H */
