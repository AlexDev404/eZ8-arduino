// Copyright (c) 2024 AlexDev404 (Immanuel DGarcia)
// Zilog 8-Bit Encore! STK500v1 Bootloader
// Structure based on optiboot - uses polling loop, not interrupts
#include <eZ8.h>
#include <stdio.h>
#include <sio.h> // non-standard I/O
#include "clock.h"
#include "uart.h"
#include "led.h"
#include "flash_tools.h"
#include "terminal.h"

#ifndef LED_START_FLASHES
#define LED_START_FLASHES 1
#endif

void main()
{
	/* Initialize hardware */
	init_timer0();
	DI();                          // Disable interrupts during init
	setFlashFreq(5530);	
	init_uart0();                  // Initialize UART (polling mode)
	init_led();
	EI();                          // Enable Interrupts (for timer, etc)
	
#if LED_START_FLASHES > 0
	/* Flash onboard LED to signal entering of bootloader */
	flash_led(LED_START_FLASHES * 2);
#endif

	/* Enter main STK500 command processing loop
	 * This is a polling loop like optiboot - NOT interrupt driven
	 * It will never return */
	stk500_loop();
}

