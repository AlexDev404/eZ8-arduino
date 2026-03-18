/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FFSTRSPN.C  built from template file STRSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_f_strspn
size_t f_f_strspn(__CONST__ char far * s1,__CONST__ char far * s2)
{
  __CONST__ char far * p = s1;

  while (*p) {
    if (!f_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

