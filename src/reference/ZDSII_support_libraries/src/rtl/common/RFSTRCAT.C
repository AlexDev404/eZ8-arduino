/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RFSTRCAT.C  built from template file STRCAT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_f_strcat
char rom * r_f_strcat(char rom * s1,__CONST__  char far * s2)
{
  register char rom * cpy = s1;

  while (*s1) ++s1;	/* Find end of s1 */
  while (*s2) *s1++ = *s2++;
  *s1 = '\0';
  return(cpy);
}

