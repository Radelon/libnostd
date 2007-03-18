#ifndef ERRNO_EOPNOTSUPP_H
#define ERRNO_EOPNOTSUPP_H

#include <errno.h>	/* EOPNOTSUPP ENOTSUP EINVAL */


#if !defined EOPNOTSUPP
#if defined ENOTSUP
#define EOPNOTSUPP	ENOTSUP
#else
#define EOPNOTSUPP	EINVAL
#endif
#endif /* !defined EOPNOTSUPP */


#endif /* !ERRNO_EOPNOTSUPP_H */
