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


/*
 * Some BSD's have EOPNOTSUPP but not ENOTSUP. Let's make sure we have both.
 */
#if !defined ENOTSUP
#if defined EOPNOTSUPP
#define ENOTSUP		EOPNOTSUPP
#else
#define ENOTSUP		EINVAL
#endif
#endif /* !defined ENOTSUP */

#if !defined EOPNOTSUPP
#if defined ENOTSUP
#define EOPNOTSUPP	ENOTSUP
#else
#define EOPNOTSUPP	EINVAL
#endif
#endif /* !defined EOPNOTSUPP */


#endif /* LIBCOM_COM_ERRNO_H */
