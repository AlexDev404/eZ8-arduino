/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NFREE.C  built from template file FREE.TPL
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
void n_free(void near * ap)
{
  nearHEADER near * p;
  nearHEADER near * q;

  if (ap)
  {
    p = (nearHEADER near *)ap - 1;
    for (q = (nearHEADER near *)n_allocp;
         p <= q || p >= q->ptr;
         q = q->ptr)
      if (q >= q->ptr && (p > q || p < q->ptr))
        break;
    if (ADD_SIZE_TOnearHEADER(p) == q->ptr) {	/* join upper */
      p->size += q->ptr->size;
      p->ptr = q->ptr->ptr;
    }
    else
      p->ptr = q->ptr;
    if (ADD_SIZE_TOnearHEADER(q) == p) {		/* join lower */
      q->size += p->size;
      q->ptr = p->ptr;
    }
    else
      q->ptr = p;
    n_allocp = q;
  }
}

