/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NESTRNCAT.C  built from template file STRNCAT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_e_strncat
char near * n_e_strncat(char near * s1,__CONST__  char pageE * s2, size_t n)
{
  register char near * cpy = s1;
  while (*s1) ++s1;	/* Find end of s1 */
  while (n > 0 && *s2) *s1++ = *s2++, --n;
  *s1 = '\0';
  return(cpy);
}

