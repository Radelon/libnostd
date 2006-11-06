#ifndef LIBCOM_COM_GETTIMEOFDAY_H
#define LIBCOM_COM_GETTIMEOFDAY_H

#include <com/config.h>		/* LIBCOM_SCOPE */

#include <sys/time.h>		/* struct timeval gettimeofday(3) */

#if _WIN32

#include <sys/timeb.h>		/* struct timeval */

struct timezone;

LIBCOM_SCOPE int gettimeofday(struct timeval *, struct timezone *);

#endif /* _WIN32 */


#if LIBCOM_STATIC

#include <com/gettimeofday.c>

#endif

#endif /* LIBCOM_COM_GETTIMEOFDAY_H */
