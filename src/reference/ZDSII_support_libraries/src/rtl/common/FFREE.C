/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FFREE.C  built from template file FREE.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include "memheader.h"


/*************************************************
*
* free - free up allocated memory
*
* Inputs:
*	ap - pointer to allocated memory
*
* Returns:
*	nothing
*
*************************************************/
void f_free(void far * ap)
{
  farHEADER far * p;
  farHEADER far * q;

  if (ap)
  {
    p = (farHEADER far *)ap - 1;
    for (q = (farHEADER far *)f_allocp;
         p <= q || p >= q->ptr;
         q = q->ptr)
      if (q >= q->ptr && (p > q || p < q->ptr))
        break;
    if (ADD_SIZE_TOfarHEADER(p) == q->ptr) {	/* join upper */
      p->size += q->ptr->size;
      p->ptr = q->ptr->ptr;
    }
    else
      p->ptr = q->ptr;
    if (ADD_SIZE_TOfarHEADER(q) == p) {		/* join lower */
      q->size += p->size;
      q->ptr = p->ptr;
    }
    else
      q->ptr = p;
    f_allocp = q;
  }
}

