#ifndef LIBCOM_COM_SOCKET_H
#define LIBCOM_COM_SOCKET_H


#if !_WIN32
#define INVALID_SOCKET	-1
#define closesocket(fd)	close((fd))
#endif


#endif /* LIBCOM_COM_SOCKET_H */
