/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FREALLOC.C  built from template file REALLOC.TPL
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
#undef f_realloc
void far * f_realloc(void far * ptr, size_t size)
{
  farHEADER far * h;
  void far * p;
  far_size_type nunits;

  if (ptr) {
    nunits = size+sizeof(farHEADER);
    h = (farHEADER far *)((char far *)ptr - sizeof(farHEADER));
    if (h->size >= nunits)
      return(ptr);
    if (p = f_malloc(size)) {
      f_f_memcpy(p,ptr,size);
      f_free(ptr);
    }
    return(p);
  }
  return(f_malloc(size));
}


