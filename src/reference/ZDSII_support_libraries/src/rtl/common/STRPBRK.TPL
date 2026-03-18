#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strpbrk
char SPACE1 * PREFIX1##PREFIX2##strpbrk(__CONST__ char SPACE1 * s1,__CONST__  char SPACE2 * s2)
{
  while (*s1) {
    if (PREFIX2##strchr(s2,*s1))
      return(s1);
    ++s1;
  }
  return(0);
}

