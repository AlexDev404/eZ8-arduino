/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EMALLOC.C  built from template file MALLOC.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include "memheader.h"

static pageE pageEHEADER e_base = { &e_base, 0 };
pageE pageEHEADER* pageE e_allocp = &e_base;

/* Define NULL to the right type */
#undef NULL
#define NULL ((void pageE *)0)

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
static pageEHEADER pageE * e_morecore(unsigned int nu)
{
  char pageE * pageE_s_sbrk(int);
  register char pageE * cp;
  register pageEHEADER pageE * up;
  register pageE_size_type rnu;

  rnu = nu+sizeof(pageEHEADER);
  cp = pageE_s_sbrk(rnu);
  if (cp == (char pageE*)-1)	/* no space at all */
    return(NULL);
  up = (pageEHEADER pageE *)cp;
  up->size = rnu;
  /* put memory into free list */
  e_free((void pageE *)(up+1));
  /* return pointer to new free list head */
  return (pageEHEADER pageE *)e_allocp;
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
void pageE * e_malloc(size_t nbytes)
{
  pageEHEADER pageE * p;
  pageEHEADER pageE * q;
  pageE_size_type nunits;

  if (nbytes > (size_t)pageE_size_max-sizeof(pageEHEADER))
    return NULL;
  nunits = nbytes+sizeof(pageEHEADER);
  for ( q = e_allocp, p=q->ptr;
      ;
      q=p,p=p->ptr)
  {
    if (p->size >= nunits)
    {	/* big enough */
      if ((p->size - nunits) <= sizeof(pageEHEADER))
      {
        /* p exactly big enough, or not enough left over to use */
	q->ptr = p->ptr;
      }
      else
      {
	p->size -= nunits;
	p = ADD_SIZE_TOpageEHEADER(p);
	p->size = nunits;
      }
      e_allocp = q;
      return((void pageE *)(p+1));
    }
    if (p == (pageEHEADER pageE *)e_allocp)	/* wrapped around free list */
      if ((p = e_morecore(nunits)) == NULL)
        break;
  }
  return(NULL);	/* out of memory */
}

