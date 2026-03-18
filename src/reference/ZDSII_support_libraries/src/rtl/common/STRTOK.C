/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRTOK.C  built from template file STRTOK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strtok
char  * strtok(char  * s1,__CONST__  char  * s2)
{
  static char  * ptr;
  char  * p;
  size_t l;

  if (s1)
    ptr = s1;

/* find first char not in s2 */
  l = strspn(ptr,s2);
  if (l >= strlen(ptr))
    return(NULL);
  ptr += l;	/* ptr points to first token */

/* search for end of token */
  p = strpbrk(ptr,s2);
  if (!p) {
    s1 = ptr;
    ptr += strlen(ptr);
    return(s1); /* rest of string is in token */
  }
  *p = '\0';		/* terminate string */
  s1 = ptr;		/* save beginning pointer */
  ptr = p + 1;		/* update ptr */
  return(s1);
}

