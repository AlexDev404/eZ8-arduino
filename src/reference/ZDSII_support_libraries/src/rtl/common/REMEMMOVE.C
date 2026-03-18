/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                REMEMMOVE.C  built from template file MEMMOVE.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#include <ctype.h>


#undef r_memmove

void rom * r_e_memmove(void rom * s1,__CONST__ void pageE * s2,size_t n)
{
  register size_t i;
  unsigned char rom * t = s1;
  unsigned char rom * p1;
  unsigned __CONST__ char pageE * p2;

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
    p1 = (unsigned char rom *)s1 + n - 1;
    p2 = (unsigned char pageE *)s2 + n - 1;
    for(i=0;i<n;++i)
      *p1-- = *p2--;
  }
#endif
  return(t);
}

