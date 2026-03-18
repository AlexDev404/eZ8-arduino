/*  PUTCH.C
 *****************************************************************************
 *  Copyright (C) 2008 by  Zilog, Inc.
 *  All Rights Reserved
 ****************************************************************************/

#include <stdio.h>
#include <ez8.h>
#include <sio.h>
#include "csio.h"

static void send(char c)
{
    if (_current_port == _UART0)
    {
        /* UART0 */
        while (!(U0STAT0 & 0x04));  // Transmit Data register enabled
        U0TXD = c;                  // Send data
    }
#ifdef  EZ8_UART1
    else
    {
        /* UART1 */
        while (!(U1STAT0 & 0x04));  // Transmit Data register enabled
        U1TXD = c;                  // Send data
    }
#endif
}

reentrant unsigned char putch(char c)
{
    if (c == '\n')
        send('\r');
    send(c);
    return 0;
}
