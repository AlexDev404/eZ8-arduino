/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                REMEMCPY.C  built from template file MEMCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef r_memcpy

void rom * r_e_memcpy(void rom * s1,__CONST__  void pageE * s2, size_t n)
{
  register size_t i;
  void rom * t = s1;
  unsigned char rom * p1 = s1;
  unsigned __CONST__ char pageE * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


