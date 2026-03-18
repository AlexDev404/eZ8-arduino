/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FGETS.C  built from template file GETS.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

#define LF 10

/*************************************************
*
* gets - get a string from the uart
*	Dangerous! Buffer overrun is possible.
*
* Inputs:
*	string - address of string
*
* Returns:
*	pointer to string or NULL
*
*************************************************/
#undef f_gets
char far * f_gets(__CONST__ char far * string)
{
  char far * sptr = string;
  char chr;

  while ((chr = getchar()) != EOF) {
    if (chr == LF) {
      *sptr = '\0';
      return (string);
    } /* Remove LF */
    *(sptr++) = chr;
  }
  /* EOF encountered */
  if (sptr == string)
    return NULL;
  *sptr = '\0';
  return string;
}


