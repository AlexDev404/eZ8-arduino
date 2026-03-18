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
#undef PREFIX1##calloc
void SPACE1 * PREFIX1##calloc(size_t nmemb,size_t size)
{
  void SPACE1 * p;
  if (p = PREFIX1##malloc(nmemb*size))
    PREFIX1##memset(p,0,nmemb*size);
  return(p);
}


