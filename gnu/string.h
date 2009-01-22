#ifndef GNU_STRING_H
#define GNU_STRING_H

#if defined(_MSC_VER)
#include <string.h>
#else
#include_next <string.h>
#endif


#include <gnu/string/strnlen.h>
#include <gnu/string/strdupa.h>
#include <gnu/string/strndupa.h>


#endif /* GNU_STRING_H */
