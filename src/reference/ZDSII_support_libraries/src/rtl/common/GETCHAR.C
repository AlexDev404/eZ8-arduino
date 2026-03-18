/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stdio.h>
#include <uart.h>

/*************************************************
*
* getchar - get a character from stdin
*
* Inputs:
*	None
*
* Returns:
*	character or EOF
*
*************************************************/
int getchar(void)
{
  return (getch());
}
