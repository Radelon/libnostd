#ifndef COMPAT_WINDOWS_H
#define COMPAT_WINDOWS_H

#include <win32/windows.h>

#if _WIN32
#include_next <windows.h>
#endif

#endif /* !COMPAT_WINDOWS_H */
