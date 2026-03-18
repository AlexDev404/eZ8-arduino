/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
/* Per the 1989 C standard, this file should not have include guards.
 * One should be able  to reinclude to file, with a changed setting for
 * NODEBUG, and redefine the assert macro.  This also means no pragma once.
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef assert
# undef assert
#endif

#ifdef NDEBUG
#define assert(ignore) ((void)0)
#else
#define assert(e) if (!(e)) {\
   r_putsNOnl(R"Assertion failure: " #e ", file: " __FILE__ ", line "); \
   puts(itod(__LINE__)); \
   abort();\
}
#endif
