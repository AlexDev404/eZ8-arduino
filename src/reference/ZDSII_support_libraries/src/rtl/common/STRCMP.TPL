#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strcmp
int PREFIX1##PREFIX2##strcmp(register __CONST__ char SPACE1 * s1, register __CONST__ char SPACE2 * s2)
{
  while (*s1 && *s1 == *s2)
    s1++, s2++;
  return(*s1 - *s2);
}

