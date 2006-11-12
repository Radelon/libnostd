#ifndef LIBCOM_COM_SOCKET_H
#define LIBCOM_COM_SOCKET_H

#include <errno.h>		/* errno */

#if !_WIN32
#define INVALID_SOCKET		-1
#define closesocket(fd)		close((fd))
#define WSAGetLastError()	errno
#endif


#endif /* LIBCOM_COM_SOCKET_H */
