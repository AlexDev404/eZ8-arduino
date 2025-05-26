#pragma once
#include <eZ8.h>
#include <stdio.h>
#include <sio.h> // non-standard I/O

// ==================== SOFTWARE VERSION =============================
#define HW_VER	 0x02
#define SW_MAJOR 0x01
#define SW_MINOR 0x10

void isr_uart0_rx(void);