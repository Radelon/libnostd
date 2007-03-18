#ifndef WINDOWS_CLOSESOCKET_H
#define WINDOWS_CLOSESOCKET_H


#if HAVE_CLOSESOCKET || _WIN32
#define WANT_CLOSESOCKET_WIN32
#else
#define WANT_CLOSESOCKET_SUSv3
#endif


#if WANT_CLOSESOCKET_WIN32

#include <winsock2.h>	/* closesocket() */

#endif /* WANT_CLOSESOCKET_WIN32 */


#if WANT_CLOSESOCKET_SUSv3

#include <sys/socket.h>	/* SHUT_RDWR shutdown(2) */

#define closesocket(s)	shutdown((s), SHUT_RDWR)

#endif /* WANT_CLOSESOCKET_SUSv3 */


#endif /* WINDOWS_CLOSESOCKET_H */
