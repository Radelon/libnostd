#ifndef LIBCOM_COM_GETTIMEOFDAY_H
#define LIBCOM_COM_GETTIMEOFDAY_H

#include <com/config.h>		/* LIBCOM_SCOPE */

#include <sys/time.h>		/* struct timeval gettimeofday(3) */


#ifndef LIBCOM_GETTIMEOFDAY_SCOPE
#define LIBCOM_GETTIMEOFDAY_SCOPE	LIBCOM_SCOPE
#endif


#if _WIN32

#include <sys/timeb.h>		/* struct timeval */

struct timezone;

LIBCOM_GETTIMEOFDAY_SCOPE int gettimeofday(struct timeval *, struct timezone *);

#endif /* _WIN32 */


#if LIBCOM_STATIC

#include <com/gettimeofday.c>

#endif

#endif /* LIBCOM_COM_GETTIMEOFDAY_H */
