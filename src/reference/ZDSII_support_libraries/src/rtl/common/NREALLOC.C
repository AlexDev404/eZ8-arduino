/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NREALLOC.C  built from template file REALLOC.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <format.h>
#include "memheader.h"

/*************************************************
*
* realloc - change the size of an allocated block
*
* Inputs:
*	ptr - pointer to allocated memory
*	size - new size of memory
*
* Returns:
*	pointer to block - may have changed
*
*************************************************/
#undef n_realloc
void near * n_realloc(void near * ptr, size_t size)
{
  nearHEADER near * h;
  void near * p;
  near_size_type nunits;

  if (ptr) {
    nunits = size+sizeof(nearHEADER);
    h = (nearHEADER near *)((char near *)ptr - sizeof(nearHEADER));
    if (h->size >= nunits)
      return(ptr);
    if (p = n_malloc(size)) {
      n_n_memcpy(p,ptr,size);
      n_free(ptr);
    }
    return(p);
  }
  return(n_malloc(size));
}


