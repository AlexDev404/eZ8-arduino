/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EFMEMCPY.C  built from template file MEMCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef e_memcpy

void pageE * e_f_memcpy(void pageE * s1,__CONST__  void far * s2, size_t n)
{
  register size_t i;
  void pageE * t = s1;
  unsigned char pageE * p1 = s1;
  unsigned __CONST__ char far * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


