#ifndef WIN32_WINSOCK2_H
#define WIN32_WINSOCK2_H

#include <errno.h>


#if HAVE_WINSOCK2_H || _WIN32
#if defined(_MSC_VER)
#include <winsock2.h>
#else
#include_next <winsock2.h>
#endif
#endif


#if !defined(HAVE_WSAGETLASTERROR)
#if _WIN32
#define HAVE_WSAGETLASTERROR	1
#else
#define HAVE_WSAGETLASTERROR	0
#endif
#endif

#if !HAVE_WSAGETLASTERROR
#define WSAGetLastError()	errno
#endif


#if !defined(INVALID_SOCKET)
#define INVALID_SOCKET	(-1)
#endif


#if !defined(HAVE_CLOSESOCKET)
#if _WIN32
#define HAVE_CLOSESOCKET	1
#else
#define HAVE_CLOSESOCKET	0
#endif
#endif


#if !HAVE_CLOSESOCKET

#include <unistd.h>	/* close(2) */

#define closesocket(s)	close((s))

#endif /* !HAVE_CLOSESOCKET */


#endif /* WIN32_WINSOCK2_H */
