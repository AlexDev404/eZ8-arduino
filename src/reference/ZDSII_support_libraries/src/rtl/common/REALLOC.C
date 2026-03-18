/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                REALLOC.C  built from template file REALLOC.TPL
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
#undef realloc
void  * realloc(void  * ptr, size_t size)
{
  HEADER  * h;
  void  * p;
  _size_type nunits;

  if (ptr) {
    nunits = size+sizeof(HEADER);
    h = (HEADER  *)((char  *)ptr - sizeof(HEADER));
    if (h->size >= nunits)
      return(ptr);
    if (p = malloc(size)) {
      memcpy(p,ptr,size);
      free(ptr);
    }
    return(p);
  }
  return(malloc(size));
}


