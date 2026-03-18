/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RESTRNCAT.C  built from template file STRNCAT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_e_strncat
char rom * r_e_strncat(char rom * s1,__CONST__  char pageE * s2, size_t n)
{
  register char rom * cpy = s1;
  while (*s1) ++s1;	/* Find end of s1 */
  while (n > 0 && *s2) *s1++ = *s2++, --n;
  *s1 = '\0';
  return(cpy);
}

