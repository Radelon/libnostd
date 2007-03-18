
#ifndef SYS_PARAM_COUNTING_H
#define SYS_PARAM_COUNTING_H


#if HAVE_SYS_PARAM_COUNTING
#define WANT_SYS_PARAM_COUNTING_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_COUNTING_WIN32	1
#else
#define WANT_SYS_PARAM_COUNTING_BSD	1
#endif


#if WANT_SYS_PARAM_COUNTING_BSD

#include <sys/param.h>	/* howmany roundup powerof2 */

#endif /* WANT_SYS_PARAM_COUNTING_BSD */


#if WANT_SYS_PARAM_COUNTING_WIN32

#if !defined howmany
#define howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

#if !defined roundup
#define roundup(x, y)	((((x) + ((y) - 1)) / (y)) * (y))
#endif

#if !defined powerof2
#define powerof2(x)	((((x) - 1) & (x)) == 0)
#endif

#endif /* WANT_SYS_PARAM_COUNTING_WIN32 */


#endif /* SYS_PARAM_COUNTING_H
