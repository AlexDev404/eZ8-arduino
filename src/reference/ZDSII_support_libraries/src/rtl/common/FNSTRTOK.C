/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FNSTRTOK.C  built from template file STRTOK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_n_strtok
char far * f_n_strtok(char far * s1,__CONST__  char near * s2)
{
  static char far * ptr;
  char far * p;
  size_t l;

  if (s1)
    ptr = s1;

/* find first char not in s2 */
  l = f_n_strspn(ptr,s2);
  if (l >= f_strlen(ptr))
    return(NULL);
  ptr += l;	/* ptr points to first token */

/* search for end of token */
  p = f_n_strpbrk(ptr,s2);
  if (!p) {
    s1 = ptr;
    ptr += f_strlen(ptr);
    return(s1); /* rest of string is in token */
  }
  *p = '\0';		/* terminate string */
  s1 = ptr;		/* save beginning pointer */
  ptr = p + 1;		/* update ptr */
  return(s1);
}

