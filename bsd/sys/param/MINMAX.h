#ifndef BSD_SYS_PARAM_MINMAX_H
#define BSD_SYS_PARAM_MINMAX_H


#if HAVE_SYS_PARAM_MINMAX
#define WANT_SYS_PARAM_MINMAX_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_MINMAX_C99	1
#else
#define WANT_SYS_PARAM_MINMAX_BSD	1
#endif


#if WANT_SYS_PARAM_MINMAX_BSD

#include <sys/param.h>	/* MIN MAX */

#endif /* WANT_SYS_PARAM_MINMAX_BSD */


#include <bsd/sys/param/MIN.h>
#include <bsd/sys/param/MAX.h>


#endif /* BSD_SYS_PARAM_MINMAX_H */
