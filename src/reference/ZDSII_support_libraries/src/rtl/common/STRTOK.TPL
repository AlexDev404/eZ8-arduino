#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strtok
char SPACE1 * PREFIX1##PREFIX2##strtok(char SPACE1 * s1,__CONST__  char SPACE2 * s2)
{
  static char SPACE1 * ptr;
  char SPACE1 * p;
  size_t l;

  if (s1)
    ptr = s1;

/* find first char not in s2 */
  l = PREFIX1##PREFIX2##strspn(ptr,s2);
  if (l >= PREFIX1##strlen(ptr))
    return(NULL);
  ptr += l;	/* ptr points to first token */

/* search for end of token */
  p = PREFIX1##PREFIX2##strpbrk(ptr,s2);
  if (!p) {
    s1 = ptr;
    ptr += PREFIX1##strlen(ptr);
    return(s1); /* rest of string is in token */
  }
  *p = '\0';		/* terminate string */
  s1 = ptr;		/* save beginning pointer */
  ptr = p + 1;		/* update ptr */
  return(s1);
}

