// (c) 2024 AlexDev404
#include <ez8.h>
#include <sio.h> // putch(char)
#include "led.h"

void setStatus( int status )
{
	 ProgStat = status; 		//Program status
}

void init_led(){

  PCADDR 	= 0x01;     // PC Data Dir
  PCCTL		&= 0xF7;	// PC3 as Output
  LEDEN		= 0x08;		// PC3 uses LED drive
  LEDLVLH   = 0x08;		// PC3 Led Driver current = 13ma
  LEDLVLL   = 0x00;
  PCOUT &= 0xF7;	    // Turn off PC3 Led
}

void flash_led(int led_flash_count) {
	int i = 0;
	while(i < led_flash_count){
		//putch('A');
		if(ProgStat != BUSY){
			//putch('I');
			PCOUT |= 0x08;	// Turn on PC3 LED
			ProgStat = BUSY;
			i++;
		} else {
			PCOUT &= 0xF7;	// Turn off PC3 LED
		}
	}
	PCOUT &= 0xF7;	// Turn off PC3 LED after the loop
}