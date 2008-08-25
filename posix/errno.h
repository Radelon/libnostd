#ifndef POSIX_ERRNO_H
#define POSIX_ERRNO_H


#if defined(_MSC_VER)
#include <errno.h>
#else
#include_next <errno.h>
#endif


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


#endif /* POSIX_ERRNO_H */
