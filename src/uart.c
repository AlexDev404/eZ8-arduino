/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include "uart.h"

void init_uart0(void)
{
    /* Initialize UART0 for STK500 communication
     * Note: We use polling-based I/O (getch/putch from sio.h),
     * NOT interrupt-driven. This matches how optiboot and other
     * Arduino bootloaders work - they poll in main loop.
     */
    init_uart(_UART0, _DEFFREQ, BAUD_115200); // Setup Uart0 at 115200 baud
    select_port(_UART0);                      // Select port for stdio
    /* No interrupt setup - we use polling in main loop */
}
