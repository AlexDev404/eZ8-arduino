/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RRSTRSPN.C  built from template file STRSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_r_strspn
size_t r_r_strspn(__CONST__ char rom * s1,__CONST__ char rom * s2)
{
  __CONST__ char rom * p = s1;

  while (*p) {
    if (!r_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

