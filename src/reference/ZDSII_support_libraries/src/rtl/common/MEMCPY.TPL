#include <stddef.h>
#include <string.h>
#undef PREFIX1##memcpy

void SPACE1 * PREFIX1##PREFIX2##memcpy(void SPACE1 * s1,__CONST__  void SPACE2 * s2, size_t n)
{
  register size_t i;
  void SPACE1 * t = s1;
  unsigned char SPACE1 * p1 = s1;
  unsigned __CONST__ char SPACE2 * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


