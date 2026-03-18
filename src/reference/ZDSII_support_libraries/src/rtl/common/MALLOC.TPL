#include <stddef.h>
#include <stdlib.h>
#include "memheader.h"

static SPACE1 SPACE1##HEADER PREFIX1##base = { &PREFIX1##base, 0 };
SPACE1 SPACE1##HEADER* SPACE1 PREFIX1##allocp = &PREFIX1##base;

/* Define NULL to the right type */
#undef NULL
#define NULL ((void SPACE1 *)0)

/*************************************************
*
* morecore - get more memory for heap
*
* Inputs:
*	nu - number of units
*
* Returns:
*	the address of the new memory
*
*************************************************/
static SPACE1##HEADER SPACE1 * PREFIX1##morecore(unsigned int nu)
{
  char SPACE1 * SPACE1##_s_sbrk(int);
  register char SPACE1 * cp;
  register SPACE1##HEADER SPACE1 * up;
  register SPACE1##_size_type rnu;

  rnu = nu+sizeof(SPACE1##HEADER);
  cp = SPACE1##_s_sbrk(rnu);
  if (cp == (char SPACE1*)-1)	/* no space at all */
    return(NULL);
  up = (SPACE1##HEADER SPACE1 *)cp;
  up->size = rnu;
  /* put memory into free list */
  PREFIX1##free((void SPACE1 *)(up+1));
  /* return pointer to new free list head */
  return (SPACE1##HEADER SPACE1 *)PREFIX1##allocp;
}



/*************************************************
*
* malloc - allocate heap storage
*
* Inputs:
*	nbytes - number of bytes to allocate
*
* Returns:
*	the address of the memory or NULL
*
*************************************************/
void SPACE1 * PREFIX1##malloc(size_t nbytes)
{
  SPACE1##HEADER SPACE1 * p;
  SPACE1##HEADER SPACE1 * q;
  SPACE1##_size_type nunits;

  if (nbytes > (size_t)SPACE1##_size_max-sizeof(SPACE1##HEADER))
    return NULL;
  nunits = nbytes+sizeof(SPACE1##HEADER);
  for ( q = PREFIX1##allocp, p=q->ptr;
      ;
      q=p,p=p->ptr)
  {
    if (p->size >= nunits)
    {	/* big enough */
      if ((p->size - nunits) <= sizeof(SPACE1##HEADER))
      {
        /* p exactly big enough, or not enough left over to use */
	q->ptr = p->ptr;
      }
      else
      {
	p->size -= nunits;
	p = ADD_SIZE_TO##SPACE1##HEADER(p);
	p->size = nunits;
      }
      PREFIX1##allocp = q;
      return((void SPACE1 *)(p+1));
    }
    if (p == (SPACE1##HEADER SPACE1 *)PREFIX1##allocp)	/* wrapped around free list */
      if ((p = PREFIX1##morecore(nunits)) == NULL)
        break;
  }
  return(NULL);	/* out of memory */
}

