#ifndef LIBCOM_COM_STRING_H
#define LIBCOM_COM_STRING_H

#include <string.h>	/* strcmp(3) */


#if !defined STRINGIFY
#define STRINGIFY_(s)	#s
#define STRINGIFY(s)	STRINGIFY_(s)
#endif


#if !defined streq
#define streq(a, b)		(0 == strcmp((a), (b)))
#endif

#if !defined strneq
#define strneq(a, b, z)		(0 == strncmp((a), (b), (z)))
#endif

#if !defined strcaseeq
#define strcaseeq(a, b)		(0 == strcasecmp((a), (b)))
#endif

#if !defined strncaseeq
#define strncaseeq(a, b, z)	(0 == strncasecmp((a), (b), (z)))
#endif


#include <com/strlcpy.h>

#include <com/strlcat.h>


#endif /* LIBCOM_COM_STRING_H */
