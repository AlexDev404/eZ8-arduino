/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                MEMCPY.C  built from template file MEMCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef memcpy

void  * memcpy(void  * s1,__CONST__  void  * s2, size_t n)
{
  register size_t i;
  void  * t = s1;
  unsigned char  * p1 = s1;
  unsigned __CONST__ char  * p2 = s2;

  for(i=0;i<n;++i) {
    *p1++ = *p2++;
  }
  return(t);
}


