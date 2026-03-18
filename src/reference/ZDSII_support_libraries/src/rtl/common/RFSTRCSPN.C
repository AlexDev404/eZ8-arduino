/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RFSTRCSPN.C  built from template file STRCSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_f_strcspn
size_t r_f_strcspn( __CONST__ char rom * s1, __CONST__ char far * s2)
{
   __CONST__ char rom * p = s1;

  while (*p) {
    if (f_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p-s1);
}

