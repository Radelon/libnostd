#ifndef LIBCOM_COM_STRLCPY_H
#define LIBCOM_COM_STRLCPY_H

#include <com/config.h>	/* LIBCOM_SCOPE */

#include <stddef.h>	/* size_t */


#ifndef LIBCOM_STRLCPY_SCOPE
#define LIBCOM_STRLCPY_SCOPE	LIBCOM_SCOPE
#endif

#if !defined __OpenBSD__ && !defined __NetBSD__ && !defined __FreeBSD__ && !defined HAVE_STRLCPY
LIBCOM_STRLCPY_SCOPE size_t strlcpy(char *, const char *, size_t);
#endif


#if LIBCOM_STATIC
#include <com/strlcpy.c>
#endif

#endif /* LIBCOM_COM_STRLCPY_H */
