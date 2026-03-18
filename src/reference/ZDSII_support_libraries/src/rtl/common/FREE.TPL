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
void PREFIX1##free(void SPACE1 * ap)
{
  SPACE1##HEADER SPACE1 * p;
  SPACE1##HEADER SPACE1 * q;

  if (ap)
  {
    p = (SPACE1##HEADER SPACE1 *)ap - 1;
    for (q = (SPACE1##HEADER SPACE1 *)PREFIX1##allocp;
         p <= q || p >= q->ptr;
         q = q->ptr)
      if (q >= q->ptr && (p > q || p < q->ptr))
        break;
    if (ADD_SIZE_TO##SPACE1##HEADER(p) == q->ptr) {	/* join upper */
      p->size += q->ptr->size;
      p->ptr = q->ptr->ptr;
    }
    else
      p->ptr = q->ptr;
    if (ADD_SIZE_TO##SPACE1##HEADER(q) == p) {		/* join lower */
      q->size += p->size;
      q->ptr = p->ptr;
    }
    else
      q->ptr = p;
    PREFIX1##allocp = q;
  }
}

