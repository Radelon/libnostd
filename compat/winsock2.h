#ifndef COMPAT_WINSOCK2_H
#define COMPAT_WINSOCK2_H

#if _WIN32
#include_next <winsock2.h>
#endif

#include <win32/winsock2.h>

#endif /* !COMPAT_WINSOCK2_H */
