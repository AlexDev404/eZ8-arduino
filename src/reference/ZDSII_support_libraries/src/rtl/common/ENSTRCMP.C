/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ENSTRCMP.C  built from template file STRCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_n_strcmp
int e_n_strcmp(register __CONST__ char pageE * s1, register __CONST__ char near * s2)
{
  while (*s1 && *s1 == *s2)
    s1++, s2++;
  return(*s1 - *s2);
}

