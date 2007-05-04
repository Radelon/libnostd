#ifndef WIN32_WINDOWS_SETLASTERROR_H
#define WIN32_WINDOWS_SETLASTERROR_H


#if HAVE_SETLASTERROR || _WIN32
#define WANT_SETLASTERROR_WIN32	1
#else
#define WANT_SETLASTERROR_C99	1
#endif


#if WANT_SETLASTERROR_WIN32

#include <windows.h>	/* SetLastError() */

#endif /* WANT_SETLASTERROR_WIN32 */


#if WANT_SETLASTERROR_C99

#include <errno.h>	/* errno */

#define SetLastError(e)	(errno = (e))

#endif /* WANT_SETLASTERROR_C99 */


#endif /* WIN32_WINDOWS_SETLASTERROR_H */