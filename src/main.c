// Copyright (c) 2024 AlexDev404 (Immanuel DGarcia)
// Zilog 8-Bit Encore! STK500v1 Bootloader
// Structure based on optiboot - uses polling loop, not interrupts
#include <eZ8.h>
#include "clock.h"
#include "uart.h"
#include "led.h"
#include "flash_tools.h"
#include "terminal.h"

#ifndef LED_START_FLASHES
#define LED_START_FLASHES 1
#endif

/* System clock frequency in kHz - Z8F082A internal RC oscillator is ~5.53 MHz
 * This must match the value used in uart.c for baud rate calculation */
#define SYSTEM_CLOCK_KHZ    5530

/* UART0 Status Register bit definitions for Z8 Encore! */
#define UART_RDA  0x80  /* Receive Data Available bit in U0STAT0 */

/* Maximum iterations for UART flush - prevents infinite loop if RDA stuck high */
#define UART_FLUSH_TIMEOUT  1000

/*
 * Flush any pending bytes from the UART receive buffer.
 * This prevents sync issues if garbage was received before bootloader started.
 * Uses a maximum iteration count to prevent infinite loops.
 */
static void uart_flush_rx(void) {
	volatile unsigned char dummy;
	unsigned int timeout = UART_FLUSH_TIMEOUT;
	
	/* Drain any pending data from the UART RX buffer */
	while ((U0STAT0 & UART_RDA) && timeout--) {
		dummy = U0RXD;  /* Read and discard the byte */
	}
	(void)dummy;  /* Suppress unused variable warning */
}

void main()
{
	/* Initialize hardware */
	DI();                          // Disable interrupts during init
	init_systemclock();            // Ensure clock source is configured first!
	init_timer0();
	setFlashFreq(SYSTEM_CLOCK_KHZ);	
	init_uart0();                  // Initialize UART (polling mode)
	init_led();
	
	/* Flush any garbage from UART RX buffer before enabling interrupts
	 * This prevents sync issues with avrdude if noise was received */
	uart_flush_rx();
	
	EI();                          // Enable Interrupts (for timer, etc)
	
#if LED_START_FLASHES > 0
	/* Flash onboard LED to signal entering of bootloader */
	flash_led(LED_START_FLASHES * 2);
#endif

	/* Flush UART RX buffer again after LED flash, in case avrdude
	 * sent data while we were busy flashing the LED */
	uart_flush_rx();

	/* Enter main STK500 command processing loop
	 * This is a polling loop like optiboot - NOT interrupt driven
	 * It will never return */
	stk500_loop();
}

