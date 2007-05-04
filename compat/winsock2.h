#ifndef COMPAT_WINSOCK2_H
#define COMPAT_WINSOCK2_H

#include <win32/winsock2.h>

#if _WIN32
#include_next <winsock2.h>
#endif

#endif /* !COMPAT_WINSOCK2_H */
