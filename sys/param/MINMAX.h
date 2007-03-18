
#ifndef SYS_PARAM_MINMAX_H
#define SYS_PARAM_MINMAX_H


#if HAVE_SYS_PARAM_MINMAX
#define WANT_SYS_PARAM_MINMAX_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_MINMAX_WIN32	1
#else
#define WANT_SYS_PARAM_MINMAX_BSD	1
#endif


#if WANT_SYS_PARAM_MINMAX_BSD

#include <sys/param.h>	/* MIN MAX */

#endif /* WANT_SYS_PARAM_MINMAX_BSD */


#if WANT_SYS_PARAM_MINMAX_WIN32

#if !defined MIN
#define MIN(a, b)	(((a) < (b))? (a) : (b))
#endif

#if !defined MAX
#define MAX(a, b)	(((a) > (b))? (a) : (b))
#endif

#endif /* WANT_SYS_PARAM_MINMAX_WIN32 */


#endif /* SYS_PARAM_MINMAX_H */
