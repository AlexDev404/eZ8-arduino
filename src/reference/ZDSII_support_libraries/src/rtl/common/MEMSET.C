/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                MEMSET.C  built from template file MEMSET.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef memset

PF_REENTRANT void  * memset(void  * s, int c, size_t n)
{
  unsigned char  * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

