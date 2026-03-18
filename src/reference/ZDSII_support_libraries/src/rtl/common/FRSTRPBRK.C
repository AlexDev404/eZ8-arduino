/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FRSTRPBRK.C  built from template file STRPBRK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_r_strpbrk
char far * f_r_strpbrk(__CONST__ char far * s1,__CONST__  char rom * s2)
{
  while (*s1) {
    if (r_strchr(s2,*s1))
      return(s1);
    ++s1;
  }
  return(0);
}

