#ifndef BSD_SYS_PARAM_BITMAP_H
#define BSD_SYS_PARAM_BITMAP_H


#if HAVE_SYS_PARAM_BITMAP
#define WANT_SYS_PARAM_BITMAP_BSD	1
#elif _WIN32
#define WANT_SYS_PARAM_BITMAP_C99	1
#else
#define WANT_SYS_PARAM_BITMAP_BSD	1
#endif


#if WANT_SYS_PARAM_BITMAP_BSD

#include <sys/param.h>		/* setbit clrbit isset isclr */

#endif /* WANT_SYS_PARAM_BITMAP_BSD */


#include <bsd/sys/param/setbit.h>
#include <bsd/sys/param/clrbit.h>
#include <bsd/sys/param/isset.h>
#include <bsd/sys/param/isclr.h>


#endif /* BSD_SYS_PARAM_BITMAP_H */
