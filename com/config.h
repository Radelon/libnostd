#ifndef LIBCOM_COM_CONFIG_H
#define LIBCOM_COM_CONFIG_H


#if LIBCOM_EXTERN

#define LIBCOM_EXTERN	1
#define LIBCOM_STATIC	0
#define LIBCOM_SCOPE	extern

#else

#define LIBCOM_EXTERN	0
#define LIBCOM_STATIC	1
#define LIBCOM_SCOPE	static

#endif


#endif /* LIBCOM_COM_CONFIG_H */

