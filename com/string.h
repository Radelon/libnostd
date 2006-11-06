#ifndef LIBCOM_COM_STRING_H
#define LIBCOM_COM_STRING_H

#include <com/config.h>	/* LIBCOM_SCOPE */

#include <stddef.h>	/* size_t */


#if !defined STRINGIFY
#define STRINGIFY_(s)	#s
#define STRINGIFY(s)	STRINGIFY_(s)
#endif


#include <com/strlcpy.h>
#include <com/strlcat.h>

#



#endif /* LIBCOM_COM_STRING_H */
