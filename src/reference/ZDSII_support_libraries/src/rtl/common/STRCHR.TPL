#include <stddef.h>
#include <string.h>

#undef PREFIX1##strchr
char SPACE1 * PREFIX1##strchr(__CONST__ char SPACE1 * s, int c)
{
  for(;*s;++s)
    if (*s == c)
      return(s);
  if (*s == c)
    return((char SPACE1*)s);
  return(0);
}

