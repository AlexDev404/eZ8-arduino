/*  CSIO.C
 *****************************************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 ****************************************************************************/

#include <stdio.h>
#include <ez8.h>
#include <sio.h>
#include "csio.h"

char _current_port = _UART0;

reentrant int select_port(int port)
{
    if (port == _UART0 || port == _UART1)
    {
        _current_port = port;
        return(0);  // Return success
    }
    return(1);      // Return failure
}

reentrant int init_uart(int port,unsigned long freq, unsigned long baud)
{
    unsigned long brg;
    
	/* calculate the desired communication rate */
    brg = (freq+baud*8ul)/(baud * 16);
   
    switch( port )
    {
        case _UART0:
            /* 1. set the baud-rate generater */
            U0BR = brg;        
            
            /* 2. configure GPIO for alternate function */
#if  defined(_Z8F1680)
            PAAF |= 0x30;     // enable the alternate function with the AF register
            PAAFS1 &= ~0x30;  // enable the UART0 Rx/Tx with the AFS1 register
#elif defined(_Z8FMC16)
            PAAF0 |= 0x30;    // enable the UART0 Rx/Tx with the AF0-AF1 register
            PAAF1 &= ~0x30;  
#elif defined(_Z8F0823_8PIN) || defined(_Z8F04_8PIN)  || defined(_Z8F04A_8PIN)
            PAAF |= 0x30;     // enable the alternate function with the AF register
            PAAFS1 &= ~0x30;  // enable the UART0 Rx/Tx with the AFS0-AFS1 register
            PAAFS2 &= ~0x30; 
#else
            PAAF |= 0x30;     // enable the UART0 Rx/Tx with the AF register
#endif 

            /* 3. configure UART control register 1 */
            U0CTL1 = 0x00;    // clear for normal non-Multiprocessor operation
            /* 4. configure UART control register 1 */
            U0CTL0 = 0xc0;    // Transmit enable, Receive Enable, No Parity, 1 Stop
            break;
#ifdef   EZ8_UART1
        case _UART1:
            /* 1. set the baud-rate generater */
            U1BR = brg;
            /* 2. configure GPIO for alternate function */
            PDAF |= 0x30;     // enable the UART1 Rx/Tx with the AF register
            /* 3. configure UART control register 1 */
            U1CTL1 = 0x00;    // clear for normal non-Multiprocessor operation
            /* 4. configure UART control register 1 */
            U1CTL0 = 0xc0;    // Transmit enable, Receive Enable, No Parity, 1 Stop
            break;
#endif
        default:
            // Illegal port number. Will be caught by select_port
            break;
    }
    return (select_port(port));
}

 