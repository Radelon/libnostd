#ifndef BSD_ERR_ERR_H
#define BSD_ERR_ERR_H


#if HAVE_ERR || __OpenBSD__ || __FreeBSD__ || __NetBSD__ || defined __linux__
#define WANT_ERR_BSD	1
#else
#define WANT_ERR_C99	1
#endif


#if WANT_ERR_BSD

#include <err.h>

#endif /* WANT_ERR_BSD */


#if WANT_ERR_C99

#include <stdarg.h>	/* va_list */


void err(int, const char *, ...);

void verr(int, const char *, va_list);

void errx(int, const char *, ...);

void verrx(int, const char *, va_list);

void warn(const char *, ...) {

void vwarn(const char *, va_list) {

void warnx(const char *, ...) {

void vwarnx(const char *, va_list) {

#endif /* WANT_ERR_C99 */


#endif /* BSD_ERR_ERR_H */
