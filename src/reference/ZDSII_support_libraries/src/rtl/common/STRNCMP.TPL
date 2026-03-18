#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strncmp
int PREFIX1##PREFIX2##strncmp(__CONST__ char SPACE1 * s1,__CONST__  char SPACE2 * s2, size_t n)
{
  for (; n>0 && *s1 == *s2; --n,++s1,++s2)
    if (*s1 == '\0')
      return(0);
  if (n == 0)
    return(0);
  return(*s1 - *s2);
}

