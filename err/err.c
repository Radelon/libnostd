
#if WANT_ERR_COMPAT


#include <stdio.h>	/* vsnprintf(3) */
#include <stdarg.h>	/* va_list va_start va_end */
#include <stdlib.h>	/* exit(3) */

#include <string.h>	/* strerror(3) */

#include <errno.h>


#ifndef ERR_ERR_C_BUFSIZ
#define ERR_ERR_C_BUFSIZ	256
#endif


void err(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	verr(fmt, ap);

	/* NOT REACHED */
} /* err() */


void verr(int retcode, const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[ERR_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	exit(retcode);
} /* verr() */


void errx(int retcode, const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	verrx(fmt, ap);

	/* NOT REACHED */
} /* errx() */


void verrx(int retcode, const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[ERR_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s\n", buf);

	exit(retcode);
} /* verrx() */


void warn(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	vwarn(fmt, ap);

	va_end(ap);

	return /* void */;
} /* warn() */


void vwarn(const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[ERR_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s: %s\n", buf, strerror(sys_errno));

	fflush(stderr);

	errno	= sys_errno;

	return /* void */;
} /* vwarn() */


void warnx(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);

	vwarnx(fmt, ap);

	va_end(ap);

	return /* void */;
} /* warnx() */


void vwarnx(const char *fmt, va_list args) {
	int sys_errno	= errno;
	char buf[ERR_ERR_C_BUFSIZ];

	(void)vsnprintf(buf, sizeof buf, fmt, args);

	(void)fprintf(stderr, "%s\n", buf);

	fflush(stderr);

	errno	= sys_errno;

	return /* void */;
} /* vwarnx() */


#endif /* WANT_ERR_COMPAT */