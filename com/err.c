#ifndef LIBCOM_COM_ERR_C
#define LIBCOM_COM_ERR_C

#include <com/config.h>

#include <com/err.h>


#if LIBCOM_WANT_ERR || LIBCOM_WANT_ERRX || LIBCOM_WANT_WARN || LIBCOM_WANT_WARNX

#include <stdio.h>	/* vsnprintf(3) */
#include <stdarg.h>	/* va_list va_start va_end */
#include <stdlib.h>	/* exit(3) */

#include <string.h>	/* strerror(3) */

#include <errno.h>

#endif


#if LIBCOM_WANT_ERR
LIBCOM_SCOPE void err(int retcode, const char *fmt, ...) {
	int sys_errno	= errno;
	char buf[256];
	va_list ap;

	va_start(ap, fmt);

	(void)vsnprintf(buf, sizeof buf, fmt, ap);

	va_end(ap);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	exit(retcode);
} /* err() */
#endif /* LIBCOM_WANT_ERR */


#if LIBCOM_WANT_ERRX
LIBCOM_SCOPE void errx(int retcode, const char *fmt, ...) {
	int sys_errno	= errno;
	char buf[256];
	va_list ap;

	va_start(ap, fmt);

	(void)vsnprintf(buf, sizeof buf, fmt, ap);

	va_end(ap);

	(void)fprintf(stderr, "%s\n", buf);

	exit(retcode);
} /* errx() */
#endif /* LIBCOM_WANT_ERRX */


#if LIBCOM_WANT_WARN
LIBCOM_SCOPE void warn(const char *fmt, ...) {
	int sys_errno	= errno;
	char buf[256];
	va_list ap;

	va_start(ap, fmt);

	(void)vsnprintf(buf, sizeof buf, fmt, ap);

	va_end(ap);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	fflush(stderr);

	return /* void */;
} /* warn() */
#endif /* LIBCOM_WANT_WARN */


#if LIBCOM_WANT_WARNX
LIBCOM_SCOPE void warnx(const char *fmt, ...) {
	int sys_errno	= errno;
	char buf[256];
	va_list ap;

	va_start(ap, fmt);

	(void)vsnprintf(buf, sizeof buf, fmt, ap);

	va_end(ap);

	(void)fprintf(stderr, "%s\n", buf);

	fflush(stderr);

	return /* void */;
} /* warnx() */
#endif /* LIBCOM_WANT_WARNX */


#endif /* !LIBCOM_COM_ERR_C */
