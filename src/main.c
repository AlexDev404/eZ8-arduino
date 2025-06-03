// Copyright (c) 2024 AlexDev404 (Immanuel DGarcia)
// Zilog 8-Bit Encore! STK500v1 Bootloader
#include <eZ8.h>
#include <stdio.h>
#include <sio.h> // non-standard I/O
#include "clock.h"
#include "uart.h"
#include "led.h"
#include "flash_tools.h"

#ifndef LED_START_FLASHES
#define LED_START_FLASHES 1
#endif

void main ()
{
	//init_systemclock();
	init_timer0();
	DI();
    setFlashFreq(5530);	
	init_uart0();                   // Intialize UART
	init_led();
 	EI();							// Enable Interrupts
	#if LED_START_FLASHES > 0
	/* Flash onboard LED to signal entering of bootloader */
	flash_led(LED_START_FLASHES * 2);
	#endif
	//PCOUT |= 0x08;	// Turn off PC3 Led
	//flash_led(10);

	//for(;;)						// Forever loop
	//{
		//flash_led(2);
		//putch(getch());
		
	//}

}	// End of main program
