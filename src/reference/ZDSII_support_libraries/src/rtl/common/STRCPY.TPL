#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strcpy
char SPACE1 * PREFIX1##PREFIX2##strcpy(char SPACE1 * d, __CONST__ char SPACE2 * s)
{
  char SPACE1 * cp;
  char SPACE1 * pd = d;
  __CONST__ char SPACE2 * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

