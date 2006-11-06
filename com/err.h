#ifndef LIBCOM_COM_ERR_H
#define LIBCOM_COM_ERR_H

#include <com/config.h>


#if defined __OpenBSD__ || defined __FreeBSD__ || defined __NetBSD__ || defined __linux__
#define LIBCOM_HAVE_ERR_H	1
#else
#define LIBCOM_HAVE_ERR_H	0
#endif


#if !LIBCOM_HAVE_ERR_H && !HAVE_ERR && !defined LIBCOM_WANT_ERR
#define LIBCOM_WANT_ERR		1
#endif

#if !LIBCOM_HAVE_ERR_H && !HAVE_ERRX && !defined LIBCOM_WANT_ERRX
#define LIBCOM_WANT_ERRX	1
#endif

#if !LIBCOM_HAVE_ERR_H && !HAVE_WARN && !defined LIBCOM_WANT_WARN
#define LIBCOM_WANT_ERR		1
#endif

#if !LIBCOM_HAVE_ERR_H && !HAVE_WARNX && !defined LIBCOM_WANT_WARNX
#define LIBCOM_WANT_WARNX	1
#endif


#if LIBCOM_WANT_ERR
LIBCOM_SCOPE void err(int, const char *, ...);
#endif /* LIBCOM_WANT_ERR */


#if LIBCOM_WANT_ERRX
LIBCOM_SCOPE void errx(int, const char *, ...);
#endif /* LIBCOM_WANT_ERRX */


#if LIBCOM_WANT_WARN
LIBCOM_SCOPE void warn(const char *, ...) {
#endif /* LIBCOM_WANT_WARN */


#if LIBCOM_WANT_WARNX
LIBCOM_SCOPE void warnx(const char *, ...) {
#endif /* LIBCOM_WANT_WARNX */


#if LIBCOM_STATIC
#include <com/err.c>
#endif


#endif /* LIBCOM_COM_ERR_H */
