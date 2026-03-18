/*  GETCH.C
 *****************************************************************************
 *  Copyright (C) 2008 by  Zilog, Inc.
 *  All Rights Reserved
 ****************************************************************************/

#include <stdio.h>
#include <ez8.h>
#include <sio.h>
#include "csio.h"

int getch(void)
{
    char ch = ' ';

    if (_current_port == _UART0)
    {
        while (!(U0STAT0 & 0x80));     // Wait for receive data available
        ch = U0RXD;
    }
#ifdef EZ8_UART1
    else
    {
        while (!(U1STAT0 & 0x80));     // Wait for receive data available
        ch = U1RXD;
    }
#endif
    if (ch == '\r' || ch == ('\r'|0x80))
        return '\n';

    return(ch);
}
