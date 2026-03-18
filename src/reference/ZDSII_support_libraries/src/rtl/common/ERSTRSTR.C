/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ERSTRSTR.C  built from template file STRSTR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_r_strstr
char pageE * e_r_strstr(__CONST__ char pageE * s1,__CONST__ char rom * s2)
{
  register __CONST__ char pageE * p1;
  register __CONST__ char pageE * p2;
  register __CONST__ char rom * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char pageE*)p1);
  }
  return(NULL);
}

