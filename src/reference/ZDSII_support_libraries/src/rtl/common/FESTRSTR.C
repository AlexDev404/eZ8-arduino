/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FESTRSTR.C  built from template file STRSTR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_e_strstr
char far * f_e_strstr(__CONST__ char far * s1,__CONST__ char pageE * s2)
{
  register __CONST__ char far * p1;
  register __CONST__ char far * p2;
  register __CONST__ char pageE * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char far*)p1);
  }
  return(NULL);
}

