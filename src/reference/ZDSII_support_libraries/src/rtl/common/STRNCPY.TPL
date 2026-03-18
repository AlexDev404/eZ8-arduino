#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strncpy
char SPACE1 * PREFIX1##PREFIX2##strncpy(char SPACE1 * s1,__CONST__ char SPACE2 * s2,size_t n)
{
  register size_t i;
  char SPACE1 * t = s1;

  for (i=0;i<n && *s2;++i)
    *(s1++) = *(s2++);
  for (;i<n;++i)
    *(s1++) = '\0';
  return(t);
}

