/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRSTR.C  built from template file STRSTR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strstr
char  * strstr(__CONST__ char  * s1,__CONST__ char  * s2)
{
  register __CONST__ char  * p1;
  register __CONST__ char  * p2;
  register __CONST__ char  * p3;

  for (p1 = s1; *p1; ++p1) {
    for (p2 = p1, p3 = s2; *p3 && *p2 == *p3; ++p2, ++p3) ;
    if (!*p3)
      return((char *)p1);
  }
  return(NULL);
}

