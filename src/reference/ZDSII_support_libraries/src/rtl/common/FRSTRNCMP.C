/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FRSTRNCMP.C  built from template file STRNCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_r_strncmp
int f_r_strncmp(__CONST__ char far * s1,__CONST__  char rom * s2, size_t n)
{
  for (; n>0 && *s1 == *s2; --n,++s1,++s2)
    if (*s1 == '\0')
      return(0);
  if (n == 0)
    return(0);
  return(*s1 - *s2);
}

