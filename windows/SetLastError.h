#ifndef WINDOWS_SETLASTERROR_H
#define WINDOWS_SETLASTERROR_H


#if HAVE_SETLASTERROR || _WIN32
#define WANT_SETLASTERROR_WIN32
#else
#define WANT_SETLASTERROR_COMPAT
#endif


#if WANT_SETLASTERROR_WIN32

#include <windows.h>	/* SetLastError() */

#endif /* WANT_SETLASTERROR_WIN32 */


#if WANT_SETLASTERROR_COMPAT

#include <errno.h>	/* errno */

#define SetLastError(e)	(errno = (e))

#endif /* WANT_SETLASTERROR_COMPAT */


#endif /* WINDOWS_SETLASTERROR_H */
