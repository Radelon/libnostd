#ifndef SUS_ERRNO_ENOTSUP_H
#define SUS_ERRNO_ENOTSUP_H

#include <errno.h>	/* EOPNOTSUPP ENOTSUP EINVAL */


#if !defined ENOTSUP
#if defined EOPNOTSUPP
#define ENOTSUP		EOPNOTSUPP
#else
#define ENOTSUP		EINVAL
#endif
#endif /* !defined ENOTSUP */


#endif /* !SUS_ERRNO_ENOTSUP_H */
