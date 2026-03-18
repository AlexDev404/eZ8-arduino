/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef NONSTDIO_H
#define NONSTDIO_H

#include <stdarg.h>
#include <stdio.h>
#include <eZ8.h>

#define _DEFBAUD 57600ul        // 56K baud (default)
#define _UART0   0
#define _UART1   1

reentrant int init_uart(int port,unsigned long freq, unsigned long baud);
reentrant int select_port(int port);
 
/*! Other <sio.h> prototypes are moved to <uart.h> found in include\zilog */
#include <uart.h>			         // Contains header information for UART related implementations.

#endif
