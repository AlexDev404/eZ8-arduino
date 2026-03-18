/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NNSTRSTR.C  built from template file STRSTR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_n_strstr
char near * n_n_strstr(__CONST__ char near * s1,__CONST__ char near * s2)
{
  register __CONST__ char near * p1;
  register __CONST__ char near * p2;
  register __CONST__ char near * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char near*)p1);
  }
  return(NULL);
}

