#ifndef ERR_ERR_H
#define ERR_ERR_H


#if HAVE_ERR || __OpenBSD__ || __FreeBSD__ || __NetBSD__ || defined __linux__
#define WANT_ERR_BSD
#else
#define WANT_ERR_COMPAT
#endif


#if WANT_ERR_BSD

#include <err.h>

#endif /* WANT_ERR_BSD */


#if WANT_ERR_COMPAT

#include <stdarg.h>	/* va_list */


void err(int, const char *, ...);

void verr(int, const char *, va_list);

void errx(int, const char *, ...);

void verrx(int, const char *, va_list);

void warn(const char *, ...) {

void vwarn(const char *, va_list) {

void warnx(const char *, ...) {

void vwarnx(const char *, va_list) {

#endif /* WANT_ERR_COMPAT */


#endif /* ERR_ERR_H */