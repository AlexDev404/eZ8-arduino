#include <stddef.h>
#include <string.h>

/* Define NULL to the right type */
#undef NULL
#define NULL ((void SPACE1 *)0)

#undef PREFIX1##memchr
void SPACE1 * PREFIX1##memchr(__CONST__ void SPACE1 * s, int c, size_t n)
{
  register unsigned char c2 = c;
  register unsigned char SPACE1 * p = s;

  for (;n;--n,++p)
    if (*p == c2)
      return(p);
  return (NULL);
}


