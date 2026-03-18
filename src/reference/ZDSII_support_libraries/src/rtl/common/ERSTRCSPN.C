/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ERSTRCSPN.C  built from template file STRCSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_r_strcspn
size_t e_r_strcspn( __CONST__ char pageE * s1, __CONST__ char rom * s2)
{
   __CONST__ char pageE * p = s1;

  while (*p) {
    if (r_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p-s1);
}

