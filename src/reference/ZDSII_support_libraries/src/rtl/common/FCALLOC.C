/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FCALLOC.C  built from template file CALLOC.TPL
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
#undef f_calloc
void far * f_calloc(size_t nmemb,size_t size)
{
  void far * p;
  if (p = f_malloc(nmemb*size))
    f_memset(p,0,nmemb*size);
  return(p);
}


