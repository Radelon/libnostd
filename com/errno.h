#ifndef LIBCOM_COM_ERRNO_H
#define LIBCOM_COM_ERRNO_H

#include <errno.h>		/* errno */


#if _WIN32
#if !defined errno
#define errno	GetLastError()
#endif
#else
#define GetLastError()	errno
#define SetLastError(e)	(errno = (e))
#endif


#endif /* LIBCOM_COM_ERRNO_H */
