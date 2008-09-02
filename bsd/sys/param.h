#ifndef BSD_SYS_PARAM_H
#define BSD_SYS_PARAM_H

#include <bsd/sys/param/MINMAX.h>
#include <bsd/sys/param/bitmap.h>
#include <bsd/sys/param/counting.h>

#if HAVE_SYS_PARAM_H || !_WIN32 || __MINGW32__
#include_next <sys/param.h>
#endif

#endif /* !BSD_SYS_PARAM_H */
