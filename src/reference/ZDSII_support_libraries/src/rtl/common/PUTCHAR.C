/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stdio.h>
#include <sio.h>

/*************************************************
*
* putchar - put a character to stdout
*
* Inputs:
*	character to output
*
* Returns:
*	the character written
*
*************************************************/
int putchar(int ch)
{

	return (0!=putch((char)ch)) ? EOF : ch ;

}

