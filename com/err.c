#ifndef LIBCOM_COM_ERR_C
#define LIBCOM_COM_ERR_C

#include <com/config.h>

#include <com/err.h>


#if LIBCOM_WANT_VERR || LIBCOM_WANT_VERRX || LIBCOM_WANT_VWARN || LIBCOM_WANT_VWARNX

#include <stdio.h>	/* vsnprintf(3) */
#include <stdarg.h>	/* va_list va_start va_end */
#include <stdlib.h>	/* exit(3) */

#include <string.h>	/* strerror(3) */

#include <errno.h>

#endif


#if !defined LIBCOM_COM_ERR_C_BUFSIZ
#define LIBCOM_COM_ERR_C_BUFSIZ	256
#endif


#if LIBCOM_WANT_ERR
LIBCOM_SCOPE void err(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	verr(fmt, ap);

	/* NOT REACHED */
} /* err() */
#endif /* LIBCOM_WANT_ERR */


#if LIBCOM_WANT_VERR
LIBCOM_SCOPE void verr(int retcode, const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[LIBCOM_COM_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	exit(retcode);
} /* verr() */
#endif /* LIBCOM_WANT_VERR */


#if LIBCOM_WANT_ERRX
LIBCOM_SCOPE void errx(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	verrx(fmt, ap);

	/* NOT REACHED */
} /* errx() */
#endif /* LIBCOM_WANT_ERRX */


#if LIBCOM_WANT_VERRX
LIBCOM_SCOPE void verrx(int retcode, const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[LIBCOM_COM_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s\n", buf);

	exit(retcode);
} /* verrx() */
#endif /* LIBCOM_WANT_VERRX */


#if LIBCOM_WANT_WARN
LIBCOM_SCOPE void warn(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	vwarn(fmt, ap);

	va_end(ap);

	return /* void */;
} /* warn() */
#endif /* LIBCOM_WANT_WARN */


#if LIBCOM_WANT_VWARN
LIBCOM_SCOPE void vwarn(const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[LIBCOM_COM_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	fflush(stderr);

	errno	= sys_errno;

	return /* void */;
} /* vwarn() */
#endif /* LIBCOM_WANT_VWARN */


#if LIBCOM_WANT_WARNX
LIBCOM_SCOPE void warnx(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	vwarnx(fmt, ap);

	va_end(ap);

	return /* void */;
} /* warnx() */
#endif /* LIBCOM_WANT_WARNX */


#if LIBCOM_WANT_VWARNX
LIBCOM_SCOPE void vwarnx(const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[LIBCOM_COM_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s\n", buf);

	fflush(stderr);

	errno	= sys_errno;

	return /* void */;
} /* vwarnx() */
#endif /* LIBCOM_WANT_VWARNX */


#endif /* !LIBCOM_COM_ERR_C */
