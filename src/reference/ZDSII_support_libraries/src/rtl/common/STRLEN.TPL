#include <stddef.h>
#include <string.h>

#undef PREFIX1##strlen
size_t PREFIX1##strlen(__CONST__ char SPACE1 * s)
{
  register __CONST__ char SPACE1 * p = s;
  while (*p) ++p;
  return(p - s);
}

