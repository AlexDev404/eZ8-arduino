/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FNMEMCPY.C  built from template file MEMCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef f_memcpy

void far * f_n_memcpy(void far * s1,__CONST__  void near * s2, size_t n)
{
  register size_t i;
  void far * t = s1;
  unsigned char far * p1 = s1;
  unsigned __CONST__ char near * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


