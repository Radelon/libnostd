#ifndef LIBCOM_COM_STRLCAT_H
#define LIBCOM_COM_STRLCAT_H

#include <com/config.h>	/* LIBCOM_SCOPE */

#include <stddef.h>	/* size_t */

#if !defined __OpenBSD__ && !defined HAVE_STRLCAT
LIBCOM_SCOPE size_t strlcat(char *, const char *, size_t);
#endif


#if LIBCOM_STATIC
#include <com/strlcat.c>
#endif

#endif /* LIBCOM_COM_STRLCAT_H */
