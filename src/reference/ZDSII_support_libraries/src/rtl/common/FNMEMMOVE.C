/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FNMEMMOVE.C  built from template file MEMMOVE.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#include <ctype.h>


#undef f_memmove

void far * f_n_memmove(void far * s1,__CONST__ void near * s2,size_t n)
{
  register size_t i;
  unsigned char far * t = s1;
  unsigned char far * p1;
  unsigned __CONST__ char near * p2;

#if FALSE
  if (s2 > s1)
#endif
  {
    p1 = s1;
    p2 = s2;
    for(i=0;i<n;++i)
      *p1++ = *p2++;
  }
#if FALSE
  else {
    p1 = (unsigned char far *)s1 + n - 1;
    p2 = (unsigned char near *)s2 + n - 1;
    for(i=0;i<n;++i)
      *p1-- = *p2--;
  }
#endif
  return(t);
}

