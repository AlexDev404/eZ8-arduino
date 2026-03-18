#include <stddef.h>
#include <string.h>

#undef PREFIX1##PREFIX2##strstr
char SPACE1 * PREFIX1##PREFIX2##strstr(__CONST__ char SPACE1 * s1,__CONST__ char SPACE2 * s2)
{
  register __CONST__ char SPACE1 * p1;
  register __CONST__ char SPACE1 * p2;
  register __CONST__ char SPACE2 * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char SPACE1*)p1);
  }
  return(NULL);
}

