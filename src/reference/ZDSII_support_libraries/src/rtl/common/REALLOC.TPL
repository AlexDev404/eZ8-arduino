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
#undef PREFIX1##realloc
void SPACE1 * PREFIX1##realloc(void SPACE1 * ptr, size_t size)
{
  SPACE1##HEADER SPACE1 * h;
  void SPACE1 * p;
  SPACE1##_size_type nunits;

  if (ptr) {
    nunits = size+sizeof(SPACE1##HEADER);
    h = (SPACE1##HEADER SPACE1 *)((char SPACE1 *)ptr - sizeof(SPACE1##HEADER));
    if (h->size >= nunits)
      return(ptr);
    if (p = PREFIX1##malloc(size)) {
      PREFIX1##PREFIX1##memcpy(p,ptr,size);
      PREFIX1##free(ptr);
    }
    return(p);
  }
  return(PREFIX1##malloc(size));
}


