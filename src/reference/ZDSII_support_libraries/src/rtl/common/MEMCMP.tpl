#include <string.h>
#undef PREFIX1##memcmp

int PREFIX1##PREFIX2##memcmp(__CONST__ void SPACE1 * s1,
           __CONST__ void SPACE2 * s2,
	   size_t n)
{
  register size_t i;
  register unsigned char SPACE1 * p1 = s1;
  register unsigned char SPACE2 * p2 = s2;

  for (i=0;i < n && *p1 == *p2;++i,++p1,++p2);
  if (i == n)
    return(0);
  return(*p1 - *p2);
}


