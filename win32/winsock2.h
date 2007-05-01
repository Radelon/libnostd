#ifndef WIN32_WINSOCK2_H
#define WIN32_WINSOCK2_H


#include <win32/winsock2/INVALID_SOCKET.h>
#include <win32/winsock2/WSAGetLastError.h>
#include <win32/winsock2/closesocket.h>


#if HAVE_WINSOCK2_H || _WIN32
#include_next <winsock2.h>
#endif


#endif /* WIN32_WINSOCK2_H */
