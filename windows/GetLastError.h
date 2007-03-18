#ifndef WINDOWS_GETLASTERROR_H
#define WINDOWS_GETLASTERROR_H


#if HAVE_GETLASTERROR || _WIN32
#define WANT_GETLASTERROR_WIN32
#else
#define WANT_GETLASTERROR_COMPAT
#endif


#if WANT_GETLASTERROR_WIN32

#include <windows.h>	/* GetLastError() */

#endif /* WANT_GETLASTERROR_WIN32 */


#if WANT_GETLASTERROR_COMPAT

#include <errno.h>	/* errno */

#define GetLastError()	errno

#endif /* WANT_GETLASTERROR_COMPAT */


#endif /* WINDOWS_GETLASTERROR_H */
