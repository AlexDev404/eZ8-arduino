/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EREALLOC.C  built from template file REALLOC.TPL
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
#undef e_realloc
void pageE * e_realloc(void pageE * ptr, size_t size)
{
  pageEHEADER pageE * h;
  void pageE * p;
  pageE_size_type nunits;

  if (ptr) {
    nunits = size+sizeof(pageEHEADER);
    h = (pageEHEADER pageE *)((char pageE *)ptr - sizeof(pageEHEADER));
    if (h->size >= nunits)
      return(ptr);
    if (p = e_malloc(size)) {
      e_e_memcpy(p,ptr,size);
      e_free(ptr);
    }
    return(p);
  }
  return(e_malloc(size));
}


