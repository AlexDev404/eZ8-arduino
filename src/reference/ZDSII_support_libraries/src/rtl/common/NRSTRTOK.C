/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NRSTRTOK.C  built from template file STRTOK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_r_strtok
char near * n_r_strtok(char near * s1,__CONST__  char rom * s2)
{
  static char near * ptr;
  char near * p;
  size_t l;

  if (s1)
    ptr = s1;

/* find first char not in s2 */
  l = n_r_strspn(ptr,s2);
  if (l >= n_strlen(ptr))
    return(NULL);
  ptr += l;	/* ptr points to first token */

/* search for end of token */
  p = n_r_strpbrk(ptr,s2);
  if (!p) {
    s1 = ptr;
    ptr += n_strlen(ptr);
    return(s1); /* rest of string is in token */
  }
  *p = '\0';		/* terminate string */
  s1 = ptr;		/* save beginning pointer */
  ptr = p + 1;		/* update ptr */
  return(s1);
}

