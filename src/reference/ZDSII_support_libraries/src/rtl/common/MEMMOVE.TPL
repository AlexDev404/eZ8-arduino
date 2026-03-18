#include <stddef.h>
#include <string.h>
#include <ctype.h>

TPLCOMMENT: PARM1 is TRUE or FALSE as to whether spaces are  the same

#undef PREFIX1##memmove

void SPACE1 * PREFIX1##PREFIX2##memmove(void SPACE1 * s1,__CONST__ void SPACE2 * s2,size_t n)
{
  register size_t i;
  unsigned char SPACE1 * t = s1;
  unsigned char SPACE1 * p1;
  unsigned __CONST__ char SPACE2 * p2;

#if PARM1
  if (s2 > s1)
#endif
  {
    p1 = s1;
    p2 = s2;
    for(i=0;i<n;++i)
      *p1++ = *p2++;
  }
#if PARM1
  else {
    p1 = (unsigned char SPACE1 *)s1 + n - 1;
    p2 = (unsigned char SPACE2 *)s2 + n - 1;
    for(i=0;i<n;++i)
      *p1-- = *p2--;
  }
#endif
  return(t);
}

