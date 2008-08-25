/* ==========================================================================
 * strlcat.h - Re-implementation of OpenBSD's strlcat.
 * --------------------------------------------------------------------------
 * Copyright (c) 2008  William Ahern
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ==========================================================================
 */
#ifndef BSD_STRING_STRLCAT_H
#define BSD_STRING_STRLCAT_H


#if (!defined(HAVE_STRLCAT)	\
 &&  !defined(__OpenBSD__)	\
 &&  !defined(__FreeBSD__)	\
 &&  !defined(__NetBSD__)	\
 &&  !defined(__APPLE__))
#define HAVE_STRLCAT	0
#endif


#if !HAVE_STRLCAT

#ifndef XSTRLCAT_LOOSE
#define XSTRLCAT_LOOSE	0
#endif

#include <stddef.h>	/* size_t */

#include <string.h>	/* memchr(3) strlen(3) */


#define strlcat(dst, src, lim)	xstrlcat((dst), (src), (lim))

static inline size_t xstrlcat(char *dst, const char *src, size_t lim) {
#if !XSTRLCAT_LOOSE
	/*
	 * OpenBSD treats a destination buffer missing a NUL terminator
	 * within the specfied limit specially. See OpenBSD strlcat(3).
	 */
	char *d		= memchr(dst, '\0', lim);
#else
	/*
	 * However, implementors more often optimize strlen() than memchr(),
	 * and it's not clear whether one can reach the aforementioned
	 * condition legitimately.
   	 */
	char *d		= &dst[(lim)? strlen(dst) : 0];
#endif
	char *e		= &dst[lim];
	const char *s	= src;
	const char *p;

#if !XSTRLCAT_LOOSE
	if (d && d < e) {
#else
	if (d < e) {
#endif
		do {
			if ('\0' == (*d++ = *s++))
				return d - dst - 1;
		} while (d < e);

		d[-1]	= '\0';
	}

	p	= s;

	while (*s++ != '\0')
		;;

	return lim + (s - p - 1);
} /* xstrlcat() */


#endif /* !HAVE_STRLCAT */


#endif /* BSD_STRING_STRLCAT_H */
