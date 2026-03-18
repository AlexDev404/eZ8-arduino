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

/* Enable debug banner at startup to help verify UART baud rate 
 * Set to 0 to disable (saves code space and avoids avrdude confusion) */
#ifndef DEBUG_BANNER
#define DEBUG_BANNER 0
#endif

/* Enable echo test mode - echoes every received byte back
 * Use this to verify UART RX/TX both work. Disable for avrdude! 
 * Set to 1 to enable echo test, 0 to disable */
#ifndef ECHO_TEST_MODE
#define ECHO_TEST_MODE 0
#endif

/* Protocol debug mode - shows each received command as hex before processing
 * Helps diagnose what avrdude is actually sending
 * Set to 1 to enable, 0 to disable */
#ifndef PROTOCOL_DEBUG
#define PROTOCOL_DEBUG 0
#endif

/* System clock frequency in kHz - Z8F082A internal RC oscillator is ~5.53 MHz
 * This must match the value used in uart.c for baud rate calculation */
#define SYSTEM_CLOCK_KHZ    5530

/* UART0 Status Register bit definitions for Z8 Encore! */
#define UART_RDA   0x80  /* Receive Data Available bit in U0STAT0 */
#define UART_TDRE  0x04  /* Transmit Data Register Empty */
#define UART_TXE   0x02  /* Transmitter Empty */

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

#if DEBUG_BANNER || ECHO_TEST_MODE
/*
 * Send a single character to UART (for debug output)
 * Direct register access, blocking
 */
static void debug_putchar(unsigned char ch) {
	while (!(U0STAT0 & UART_TDRE))
		;
	U0TXD = ch;
	while (!(U0STAT0 & UART_TXE))
		;
}
#endif

#if DEBUG_BANNER
/*
 * Send debug banner at startup
 * If you see "STK500" clearly in terminal, baud rate is correct
 * If you see garbage, adjust SYSTEM_CLOCK_HZ in uart.c
 */
static void send_debug_banner(void) {
	/* Send "STK500\r\n" - if readable, baud rate is correct */
	debug_putchar('S');
	debug_putchar('T');
	debug_putchar('K');
	debug_putchar('5');
	debug_putchar('0');
	debug_putchar('0');
	debug_putchar('\r');
	debug_putchar('\n');
}
#endif

#if ECHO_TEST_MODE
/*
 * Hex echo test - receives bytes and echoes them back as hex
 * Use a terminal to type characters - you'll see [XX] for each byte
 * This verifies both RX and TX work and shows exact byte values
 * 
 * Test procedure:
 * 1. Set ECHO_TEST_MODE to 1, rebuild, reflash
 * 2. Open terminal at 115200 baud
 * 3. You should see "ECHO: " at startup
 * 4. Type 'A' - you should see [41]
 * 5. Type '0' - you should see [30] (this is CMD_STK_GET_SYNC)
 * 6. Type ' ' - you should see [20] (this is CRC_EOP)
 */
static void echo_test_loop(void) {
	unsigned char ch;
	/* Send startup message */
	debug_putchar('E');
	debug_putchar('C');
	debug_putchar('H');
	debug_putchar('O');
	debug_putchar(':');
	debug_putchar(' ');
	
	for (;;) {
		/* Wait for byte */
		while (!(U0STAT0 & UART_RDA))
			;
		ch = U0RXD;
		
		/* Echo it back as hex [XX] to see exact values received */
		debug_putchar('[');
		debug_putchar("0123456789ABCDEF"[(ch >> 4) & 0x0F]);
		debug_putchar("0123456789ABCDEF"[ch & 0x0F]);
		debug_putchar(']');
	}
}
#endif

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

#if DEBUG_BANNER
	/* Send debug banner to help verify baud rate
	 * Open a terminal at 115200 baud - if you see "STK500" the rate is correct */
	send_debug_banner();
#endif

#if ECHO_TEST_MODE
	/* Echo test mode - verifies both RX and TX work
	 * Type in terminal, characters should echo back */
	echo_test_loop();  /* Never returns */
#endif
	
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

