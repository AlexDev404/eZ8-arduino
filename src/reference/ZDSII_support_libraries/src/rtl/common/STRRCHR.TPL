#include <stddef.h>
#include <string.h>

#undef PREFIX1##strrchr
char SPACE1 * PREFIX1##strrchr(__CONST__ char SPACE1 * s, int c)
{
  register char SPACE1 * p = s;

  while (*p) ++p; /* Find end of s */
  for ( ; p >= s; --p)
    if (*p == c)
      return((char SPACE1*) p);
  return(NULL);
}

