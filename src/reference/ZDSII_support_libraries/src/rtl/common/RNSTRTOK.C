/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RNSTRTOK.C  built from template file STRTOK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_n_strtok
char rom * r_n_strtok(__CONST__ char rom * s1,__CONST__  char near * s2)
{
  static char rom * ptr;
  char rom * p;
  size_t l;

  if (s1)
    ptr = s1;

/* find first char not in s2 */
  l = r_n_strspn(ptr,s2);
  if (l >= r_strlen(ptr))
    return(NULL);
  ptr += l;	/* ptr points to first token */

/* search for end of token */
  p = r_n_strpbrk(ptr,s2);
  if (!p) {
    s1 = ptr;
    ptr += r_strlen(ptr);
    return(s1); /* rest of string is in token */
  }
  *p = '\0';		/* terminate string */
  s1 = ptr;		/* save beginning pointer */
  ptr = p + 1;		/* update ptr */
  return(s1);
}

