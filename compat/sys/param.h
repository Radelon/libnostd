#ifndef COMPAT_SYS_PARAM_H
#define COMPAT_SYS_PARAM_H

#include <bsd/sys/param.h>

#include <nostd/sys/param.h>

#if !_WIN32
#include_next <sys/param.h>
#endif

#endif /* !COMPAT_SYS_PARAM_H */
