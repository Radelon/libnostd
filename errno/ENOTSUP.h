#ifndef ERRNO_ENOTSUP_H
#define ERRNO_ENOTSUP_H

#include <errno.h>	/* EOPNOTSUPP ENOTSUP EINVAL */


#if !defined ENOTSUP
#if defined EOPNOTSUPP
#define ENOTSUP		EOPNOTSUPP
#else
#define ENOTSUP		EINVAL
#endif
#endif /* !defined ENOTSUP */


#endif /* !ERRNO_ENOTSUP_H */
