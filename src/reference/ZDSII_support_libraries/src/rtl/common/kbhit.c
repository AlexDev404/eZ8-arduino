/*  KBHIT.C
 *****************************************************************************
 *  Copyright (C) 2008 by  Zilog, Inc.
 *  All Rights Reserved
 ****************************************************************************/

#include <stdio.h>
#include <ez8.h>
#include <sio.h>
#include "csio.h"

unsigned char kbhit(void)
{
    if (_current_port == _UART0)
    {
        if (U0STAT0 & 0x80)           // check for receive data available
            return(1);
    }
#ifdef EZ8_UART1
    else
    {
        if (U1STAT0 & 0x80)           // check for receive data available
            return(1);
    }
#endif
    return(0);
}
