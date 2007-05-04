#ifndef BSD_SYS_PARAM_COUNTING_H
#define BSD_SYS_PARAM_COUNTING_H


#if HAVE_SYS_PARAM_COUNTING
#define WANT_SYS_PARAM_COUNTING_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_COUNTING_C99	1
#else
#define WANT_SYS_PARAM_COUNTING_BSD	1
#endif


#if WANT_SYS_PARAM_COUNTING_BSD

#include <sys/param.h>		/* howmany roundup powerof2 */

#endif /* WANT_SYS_PARAM_COUNTING_BSD */


#include <bsd/sys/param/howmany.h>
#include <bsd/sys/param/roundup.h>
#include <bsd/sys/param/powerof2.h>


#endif /* !BSD_SYS_PARAM_COUNTING_H */
