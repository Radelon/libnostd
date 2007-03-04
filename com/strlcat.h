#ifndef LIBCOM_COM_STRLCAT_H
#define LIBCOM_COM_STRLCAT_H

#include <com/config.h>	/* LIBCOM_SCOPE */

#include <stddef.h>	/* size_t */


#ifndef LIBCOM_STRLCAT_SCOPE
#define LIBCOM_STRLCAT_SCOPE	LIBCOM_SCOPE
#endif

#if !defined __OpenBSD__ && !defined HAVE_STRLCAT
LIBCOM_STRLCAT_SCOPE size_t strlcat(char *, const char *, size_t);
#endif


#if LIBCOM_STATIC
#include <com/strlcat.c>
#endif

#endif /* LIBCOM_COM_STRLCAT_H */
