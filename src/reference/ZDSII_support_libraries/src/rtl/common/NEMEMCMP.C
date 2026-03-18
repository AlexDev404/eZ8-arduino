/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NEMEMCMP.C  built from template file MEMCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <string.h>
#undef n_memcmp

int n_e_memcmp(__CONST__ void near * s1,
           __CONST__ void pageE * s2,
	   size_t n)
{
  register size_t i;
  register unsigned char near * p1 = s1;
  register unsigned char pageE * p2 = s2;

  for (i=0;i < n && *p1 == *p2;++i,++p1,++p2);
  if (i == n)
    return(0);
  return(*p1 - *p2);
}


