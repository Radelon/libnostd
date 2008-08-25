#ifndef WIN32_WINDOWS_H
#define WIN32_WINDOWS_H


#if !defined(HAVE_GETLASTERROR)
#if _WIN32
#define HAVE_GETLASTERROR	1
#else
#define HAVE_GETLASTERROR	0
#endif
#endif

#if !HAVE_GETLASTERROR
#define GetLastError()	errno
#endif


#if !defined(HAVE_SETLASTERROR)
#if _WIN32
#define HAVE_SETLASTERROR	1
#else
#define HAVE_SETLASTERROR	0
#endif
#endif

#if !HAVE_SETLASTERROR
#define SetLastError(e)	(errno = (e))
#endif


#if HAVE_WINDOWS_H || _WIN32
#if defined(_MSC_VER)
#include <windows.h>
#else
#include_next <windows.h>
#endif
#endif


#endif /* WIN32_WINDOWS_H */
