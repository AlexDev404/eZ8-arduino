/*************************************************
 *  Copyright (C) 1999-2012 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stdlib.h>

#undef free
void free(void * ap)
{
/* Simply call the appropriate near/far version */
#if (__MODEL__ == 0)
   n_free(ap);
#else
   f_free(ap);
#endif
}
