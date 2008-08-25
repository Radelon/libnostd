/* ==========================================================================
 * strlcpy.h - Re-implementation of OpenBSD's strlcpy.
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
#ifndef BSD_STRING_STRLCPY_H
#define BSD_STRING_STRLCPY_H


#if (!defined(HAVE_STRLCPY)	\
 &&  !defined(__OpenBSD__)	\
 &&  !defined(__FreeBSD__)	\
 &&  !defined(__NetBSD__)	\
 &&  !defined(__APPLE__))
#define HAVE_STRLCPY	0
#endif


#if !HAVE_STRLCPY

#include <stddef.h>	/* size_t */

#define strlcpy(dst, src, lim)	xstrlcpy((dst), (src), (lim))

static inline size_t xstrlcpy(char *dst, const char *src, size_t lim) {
	char *d		= dst;
	char *e		= &dst[lim];
	const char *s	= src;

	if (d < e) {
		do {
			if ('\0' == (*d++ = *s++))
				return s - src - 1;
		} while (d < e);

		d[-1]	= '\0';
	}

	while (*s++ != '\0')
		;;

	return s - src - 1;
} /* xstrlcpy() */

#endif /* !HAVE_STRLCPY */


#endif /* BSD_STRING_STRLCPY_H */
