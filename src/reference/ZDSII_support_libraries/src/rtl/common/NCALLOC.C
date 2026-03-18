/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NCALLOC.C  built from template file CALLOC.TPL
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
#undef n_calloc
void near * n_calloc(size_t nmemb,size_t size)
{
  void near * p;
  if (p = n_malloc(nmemb*size))
    n_memset(p,0,nmemb*size);
  return(p);
}


