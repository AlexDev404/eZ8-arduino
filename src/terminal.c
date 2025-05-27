#include "terminal.h"
#include "stk500.h"
#include "util.h"
#include "boot_tools.h"
#include "flash_tools.h"

register UINT16 address = 0x400; // Sector 1 and beyond
register UINT16 length;

#define RAMSTART  (0x100)
#define NRWWSTART (0x1800)
#define buff      ((UINT8*)(RAMSTART))
UINT8 character = ((UINT8)((void*)(0x1C00))); // Start of sector 7

//////////////////////////////////////////////////////////
//Interrupt routine

#pragma interrupt
void isr_uart0_rx(void) 
{
	UINT8 inputch = getch();
    //putch(getch());
	switch(inputch){
		case '*':
		{
			puts("\nUART Terminal\n===\n\nType a command to begin.\n");
		    while(1){ // No escape
				switch(getch()){
					case 'R':
					{
						// Read byte from memory
						puts("Reading byte from memory.\n");
						// Read byte and display
						putch(character);
						puts("\n\nSuccess.");
						break;
						
					}
					case 'W':
					{
						char str[10];
						puts("Writing byte to memory. Reboot to check to see if it has written.\n");
						// Write a byte to memory
						//character = 'X';
						// Check flash
						puts("Flash stat\n==");
						sprintf(str, "0x%02X", checkFlash());
						puts(str);
						unlockFlash();
						sprintf(str, "0x%02X", checkFlash());
						puts("Flash stat\n==");
						puts(str);
						puts("Success.\n");
						break;
					}
					default:
						puts("notFound");
						break;
				}
			}
			break;
		}	
		case CMD_STK_GET_SIGN_ON:
			//trigger_watchdog(); // FUTURE
			if (inputch == STK_INSYNC) {
				string_response(STK_SIGN_ON_MESSAGE);
				
			}
			break;
		case CMD_STK_GET_SYNC:
			sync_ok_response();
		    break;
		case CMD_STK_GET_PARAMETER:
			{
				// trigger_watchdog(); // FUTURE
				char ch2 = getch();
				if(ch2 == PARAM_STK_HW_VER) byte_response(HW_VER);		// Hardware version
				else if(ch2 == PARAM_STK_SW_MAJOR) byte_response(SW_MAJOR);	// Software major version
				else if(ch2 == PARAM_STK_SW_MINOR) byte_response(SW_MINOR);	// Software minor version
				else if(ch2 == PARAM_STK500_TOPCARD_DETECT) byte_response(0x03);		// Unknown but seems to be required by avr studio 3.56
				else byte_response(STK_NULL);				// Covers various unnecessary responses we don't care about
			}
			break;
		case CMD_STK_LOAD_ADDRESS:
			{
			   // Load an address in memory
		       UINT16 newAddress;
		       newAddress = getch();
		       newAddress = (newAddress & 0xff) | (getch() << 8);
		       newAddress += newAddress; // Convert from word address to byte address
		       address = newAddress;
		       sync_ok_response();
			   //trigger_watchdog(); // FUTURE
			}
		       break;
		case CMD_STK_PROG_PAGE:
		{
			// Program a page, length in big endian and in bytes
		    // Program the flash memory
			UINT8 *buffPtr;
			UINT16 addrPtr;
			getch(); // Skip bytes high
			length = getch(); // Content-Length of data
			getch(); // Skip memtype
			
			// If we are in a RWW section, start a page erase
			//if(address < NRWWSTART) __boot_page_erase_short((UINT16)(void*)address); // FUTURE
			
			// Read in the page contents
			buffPtr = buff;
			do *buffPtr++ = getch(); // Populate the buffer with
			while(--length); // the contents from the serial
			
			// Check if we have a terminator and then reply
			//trigger_watchdog(); // FUTURE
			
			// Check if the erase is complete
			// check_if_pageerase_iscomplete(); // FUTURE
			
			// Copy the buffer into the program memory (below the bootloader)
			buffPtr = buff;
			addrPtr = (UINT16)(void*)address; // Where we will copy into
			inputch = 1024 / 2;  // The number of pages to copy
			//do {
				// TODO: Write into the program memory
			//} while(--inputch);
			
			// check_if_flashwrite_iscomplete(); // FUTURE
			
			sync_ok_response();
		}
			break; 
		case CMD_STK_READ_PAGE:
		{
			// Read the requested memory block and return it back
			getch(); // Skip bytes-high
			length = getch(); // Bytes-low
			getch(); // Skip mem-type
			
			sync_ok_response();
			
			// trigger_watchdog(); // FUTURE
			// do putch(read_address(address++));
			// while(--length);
		}
			break;
		/*case CMD_STK_PROG_FLASH:
			// TODO: Program the device
			sync_ok_response();
			break;*/
		case CMD_STK_READ_SIGN:
		{
			putch(STK_INSYNC);
			// READ SIGN - return what Avrdude wants to hear
			putch(PROPS_SIGNATURE_0);
			putch(PROPS_SIGNATURE_1);
			putch(PROPS_SIGNATURE_2);    
			putch(STK_OK);
		}
            break;		
		case CMD_STK_SET_DEVICE:
		case CMD_STK_SET_DEVICE_EXT:
		case CMD_STK_UNIVERSAL:
		case CMD_STK_CHIP_ERASE:
		case CMD_STK_SET_PARAMETER:
		case CMD_STK_UNIVERSAL_MULTI:
		default:
			sync_ok_response();
	}
}