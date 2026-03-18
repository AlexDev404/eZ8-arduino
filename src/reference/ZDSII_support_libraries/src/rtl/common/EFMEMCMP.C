/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EFMEMCMP.C  built from template file MEMCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <string.h>
#undef e_memcmp

int e_f_memcmp(__CONST__ void pageE * s1,
           __CONST__ void far * s2,
	   size_t n)
{
  register size_t i;
  register unsigned char pageE * p1 = s1;
  register unsigned char far * p2 = s2;

  for (i=0;i < n && *p1 == *p2;++i,++p1,++p2);
  if (i == n)
    return(0);
  return(*p1 - *p2);
}


