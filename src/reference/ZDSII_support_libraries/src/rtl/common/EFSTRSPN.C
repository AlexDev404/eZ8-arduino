/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EFSTRSPN.C  built from template file STRSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_f_strspn
size_t e_f_strspn(__CONST__ char pageE * s1,__CONST__ char far * s2)
{
  __CONST__ char pageE * p = s1;

  while (*p) {
    if (!f_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

