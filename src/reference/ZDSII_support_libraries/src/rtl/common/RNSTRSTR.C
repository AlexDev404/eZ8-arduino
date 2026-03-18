/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RNSTRSTR.C  built from template file STRSTR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_n_strstr
char rom * r_n_strstr(__CONST__ char rom * s1,__CONST__ char near * s2)
{
  register __CONST__ char rom * p1;
  register __CONST__ char rom * p2;
  register __CONST__ char near * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char rom*)p1);
  }
  return(NULL);
}

