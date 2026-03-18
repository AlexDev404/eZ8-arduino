#include <stddef.h>
#include <string.h>
#undef PREFIX1##memset

PF_REENTRANT void SPACE1 * PREFIX1##memset(void SPACE1 * s, int c, size_t n)
{
  unsigned char SPACE1 * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

