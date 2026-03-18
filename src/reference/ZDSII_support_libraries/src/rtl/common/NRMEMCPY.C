/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NRMEMCPY.C  built from template file MEMCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef n_memcpy

void near * n_r_memcpy(void near * s1,__CONST__  void rom * s2, size_t n)
{
  register size_t i;
  void near * t = s1;
  unsigned char near * p1 = s1;
  unsigned __CONST__ char rom * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


