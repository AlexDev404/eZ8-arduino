/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FESTRNCMP.C  built from template file STRNCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_e_strncmp
int f_e_strncmp(__CONST__ char far * s1,__CONST__  char pageE * s2, size_t n)
{
  for (; n>0 && *s1 == *s2; --n,++s1,++s2)
    if (*s1 == '\0')
      return(0);
  if (n == 0)
    return(0);
  return(*s1 - *s2);
}

