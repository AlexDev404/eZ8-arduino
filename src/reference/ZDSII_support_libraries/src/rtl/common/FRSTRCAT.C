/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FRSTRCAT.C  built from template file STRCAT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_r_strcat
char far * f_r_strcat(char far * s1,__CONST__  char rom * s2)
{
  register char far * cpy = s1;

  while (*s1) ++s1;	/* Find end of s1 */
  while (*s2) *s1++ = *s2++;
  *s1 = '\0';
  return(cpy);
}

