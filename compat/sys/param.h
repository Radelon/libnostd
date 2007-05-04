#ifndef COMPAT_SYS_PARAM_H
#define COMPAT_SYS_PARAM_H

#if !_WIN32
#include_next <sys/param.h>
#endif

#include <bsd/sys/param.h>

#include <nostd/sys/param.h>

#endif /* !COMPAT_SYS_PARAM_H */
