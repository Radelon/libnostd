#ifndef BSD_STDLIB_H
#define BSD_STDLIB_H

#if defined(_MSC_VER)
#include <stdlib.h>
#else
#include_next <stdlib.h>
#endif


#include <bsd/stdlib/arc4random.h>

#include <bsd/stdlib/getprogname.h>


#endif /* BSD_STDLIB_H */
