/*************************************************
 *  Copyright (C) 1999-2012 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stdlib.h>

/* Simply call the appropriate near/far version */
#undef malloc
void *malloc(size_t nbytes)
{
#if (__MODEL__ == 0)
   return n_malloc(nbytes);
#else
   return f_malloc(nbytes);
#endif
}
