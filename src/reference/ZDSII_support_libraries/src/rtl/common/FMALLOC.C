/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FMALLOC.C  built from template file MALLOC.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include "memheader.h"

static far farHEADER f_base = { &f_base, 0 };
far farHEADER* far f_allocp = &f_base;

/* Define NULL to the right type */
#undef NULL
#define NULL ((void far *)0)

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
static farHEADER far * f_morecore(unsigned int nu)
{
  char far * far_s_sbrk(int);
  register char far * cp;
  register farHEADER far * up;
  register far_size_type rnu;

  rnu = nu+sizeof(farHEADER);
  cp = far_s_sbrk(rnu);
  if (cp == (char far*)-1)	/* no space at all */
    return(NULL);
  up = (farHEADER far *)cp;
  up->size = rnu;
  /* put memory into free list */
  f_free((void far *)(up+1));
  /* return pointer to new free list head */
  return (farHEADER far *)f_allocp;
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
void far * f_malloc(size_t nbytes)
{
  farHEADER far * p;
  farHEADER far * q;
  far_size_type nunits;

  if (nbytes > (size_t)far_size_max-sizeof(farHEADER))
    return NULL;
  nunits = nbytes+sizeof(farHEADER);
  for ( q = f_allocp, p=q->ptr;
      ;
      q=p,p=p->ptr)
  {
    if (p->size >= nunits)
    {	/* big enough */
      if ((p->size - nunits) <= sizeof(farHEADER))
      {
        /* p exactly big enough, or not enough left over to use */
	q->ptr = p->ptr;
      }
      else
      {
	p->size -= nunits;
	p = ADD_SIZE_TOfarHEADER(p);
	p->size = nunits;
      }
      f_allocp = q;
      return((void far *)(p+1));
    }
    if (p == (farHEADER far *)f_allocp)	/* wrapped around free list */
      if ((p = f_morecore(nunits)) == NULL)
        break;
  }
  return(NULL);	/* out of memory */
}

