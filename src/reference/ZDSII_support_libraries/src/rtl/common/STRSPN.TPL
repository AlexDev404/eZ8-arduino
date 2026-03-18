#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strspn
size_t PREFIX1##PREFIX2##strspn(__CONST__ char SPACE1 * s1,__CONST__ char SPACE2 * s2)
{
  __CONST__ char SPACE1 * p = s1;

  while (*p) {
    if (!PREFIX2##strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

