#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strncat
char SPACE1 * PREFIX1##PREFIX2##strncat(char SPACE1 * s1,__CONST__  char SPACE2 * s2, size_t n)
{
  register char SPACE1 * cpy = s1;
  while (*s1) ++s1;	/* Find end of s1 */
  while (n > 0 && *s2) *s1++ = *s2++, --n;
  *s1 = '\0';
  return(cpy);
}

