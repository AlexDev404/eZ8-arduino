/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NMALLOC.C  built from template file MALLOC.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include "memheader.h"

static near nearHEADER n_base = { &n_base, 0 };
near nearHEADER* near n_allocp = &n_base;

/* Define NULL to the right type */
#undef NULL
#define NULL ((void near *)0)

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
static nearHEADER near * n_morecore(unsigned int nu)
{
  char near * near_s_sbrk(int);
  register char near * cp;
  register nearHEADER near * up;
  register near_size_type rnu;

  rnu = nu+sizeof(nearHEADER);
  cp = near_s_sbrk(rnu);
  if (cp == (char near*)-1)	/* no space at all */
    return(NULL);
  up = (nearHEADER near *)cp;
  up->size = rnu;
  /* put memory into free list */
  n_free((void near *)(up+1));
  /* return pointer to new free list head */
  return (nearHEADER near *)n_allocp;
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
void near * n_malloc(size_t nbytes)
{
  nearHEADER near * p;
  nearHEADER near * q;
  near_size_type nunits;

  if (nbytes > (size_t)near_size_max-sizeof(nearHEADER))
    return NULL;
  nunits = nbytes+sizeof(nearHEADER);
  for ( q = n_allocp, p=q->ptr;
      ;
      q=p,p=p->ptr)
  {
    if (p->size >= nunits)
    {	/* big enough */
      if ((p->size - nunits) <= sizeof(nearHEADER))
      {
        /* p exactly big enough, or not enough left over to use */
	q->ptr = p->ptr;
      }
      else
      {
	p->size -= nunits;
	p = ADD_SIZE_TOnearHEADER(p);
	p->size = nunits;
      }
      n_allocp = q;
      return((void near *)(p+1));
    }
    if (p == (nearHEADER near *)n_allocp)	/* wrapped around free list */
      if ((p = n_morecore(nunits)) == NULL)
        break;
  }
  return(NULL);	/* out of memory */
}

