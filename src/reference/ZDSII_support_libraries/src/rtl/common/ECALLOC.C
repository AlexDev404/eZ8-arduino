/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ECALLOC.C  built from template file CALLOC.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*************************************************
*
* calloc - allocate and clear memory
*
* Inputs:
*	nmemb - number of bytes of an element
*	size - size of each element
*
* Returns:
*	a pointer to the allocated memory
*
*************************************************/
#undef e_calloc
void pageE * e_calloc(size_t nmemb,size_t size)
{
  void pageE * p;
  if (p = e_malloc(nmemb*size))
    e_memset(p,0,nmemb*size);
  return(p);
}


