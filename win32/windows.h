#ifndef WIN32_WINDOWS_H
#define WIN32_WINDOWS_H


#include <win32/windows/GetLastError.h>
#include <win32/windows/SetLastError.h>


#if HAVE_WINDOWS_H || _WIN32
#include_next <windows.h>
#endif


#endif /* WIN32_WINDOWS_H */
