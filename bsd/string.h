#if defined(_MSC_VER)
#include <string.h>
#else
#include_next <string.h>
#endif


#ifndef BSD_STRING_H
#define BSD_STRING_H


#include <bsd/string/strlcpy.h>
#include <bsd/string/strlcat.h>


#endif /* BSD_STRING_H */
