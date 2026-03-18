#include "terminal.h"
#include "stk500.h"
#include "util.h"
#include "boot_tools.h"
#include "flash_tools.h"

rom unsigned char* address = (rom unsigned char*)0x1000; // Page 8 and beyond

//////////////////////////////////////////////////////////
//Interrupt routine

#pragma interrupt
void isr_uart0_rx(void) 
{
	UINT8 inputch = getch();
	//char str[10];
	//char FLASHSTAT[13] = "Flash stat\n==";
    //putch(getch());
	switch(inputch){
		case '*':
		{
			puts("UART");
			break;
		}
		/*case CMD_STK_GET_SIGN_ON:
		{
			/* According to STK500 protocol spec:
			 * The PC sends this command to check if the starterkit is present
			 * Command: 0x31, Sync_CRC_EOP
			 * Response: Resp_STK_INSYNC, sign_on_message, Resp_STK_OK
			 /
			string_response(STK_SIGN_ON_MESSAGE);
			break;
		}*/
		case CMD_STK_GET_SYNC:
		{
			sync_ok_response();
			break;
		}
		case CMD_STK_GET_PARAMETER:
			{
				// trigger_watchdog(); // FUTURE
				char ch2 = getch();
				UINT8 value = STK_NULL; /* Default value for unknown parameters */
				
				/* Set the response value based on the parameter */
				if(ch2 == PARAM_STK_HW_VER) value = HW_VER; /* Hardware version */
				else if(ch2 == PARAM_STK_SW_MAJOR) value = SW_MAJOR; /* Software major version */
				else if(ch2 == PARAM_STK_SW_MINOR) value = SW_MINOR; /* Software minor version */
				else if(ch2 == PARAM_STK500_TOPCARD_DETECT) value = 0x03; /* Required by avr studio */
				
				/* The correct response format is: STK_INSYNC, parameter value, STK_OK */
				byte_response(value);
				break;
			}
		case CMD_STK_LOAD_ADDRESS:
			{
			   /* Load an address in memory
			    * According to STK500 protocol spec, this should receive two bytes
			    * (low then high) and convert from word address to byte address
			    * Command format: CMD_STK_LOAD_ADDRESS, addr_low, addr_high, Sync_CRC_EOP
			    */
		       UINT16 newAddress;
		       newAddress = (UINT16)getch();  /* Get low byte */
		       newAddress |= ((UINT16)getch() << 8);  /* Get high byte */
		       newAddress += newAddress; /* Convert from word address to byte address */
		       /* Add base offset for our flash area (0x1000) */
		       address = (rom unsigned char*)(0x1000 + newAddress);
		       
		       /* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
		       if (getch() != SPECIAL_Sync_CRC_EOP) {
		           putch(STK_NOSYNC);
		           break;
		       }
		       putch(STK_INSYNC);
		       putch(STK_OK);
			   break;
			}
		case CMD_STK_PROG_PAGE:
		{
			/* Program a page, length in big endian and in bytes */
			/* Command format: CMD_STK_PROG_PAGE, bytes_high, bytes_low, memtype, data, Sync_CRC_EOP */
			/* Response: Resp_STK_INSYNC, Resp_STK_OK */
			unsigned long addrPtr;
			unsigned int i, z = 0;
			UINT8 bytesHigh, bytesLow;
			
			bytesHigh = (UINT8)getch(); /* Get bytes high */
			bytesLow = (UINT8)getch();  /* Get bytes low - Content-Length of data in bytes */
			i = ((unsigned int)bytesHigh << 8) | bytesLow; /* Calculate total length */
			getch(); /* Skip memtype (usually 'F' 0x46 for FLASH) */
					
			/* Calculate the page address (start of page containing the target address) */
			addrPtr = (unsigned long)address;
			
			/* Erase the page if it's in our target range (0x1000 to 0x1FFF) */
			if(addrPtr >= 0x1000 && addrPtr < 0x2000) 
			{
				/* Each page is 512 bytes, so erase the page containing the address */
				UINT16 pageAddr = addrPtr & ~0x1FF; /* Clear low 9 bits to get page start address */
				pageEraseFlash(pageAddr);
				
				/* Wait for the erase to complete */
				while (FCMD != 0x03);
			}
			
			/* Write the buffer to flash memory byte by byte */
			for(z = 0; z < i; z++) {
				programFlashByte(addrPtr, getch());
				while (FCMD != 0x03);
				addrPtr++;
			}
			
			/* Update the address pointer for next operation */
			address = (rom unsigned char *)addrPtr;
			
			/* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				putch(STK_NOSYNC);
				break;
			}
			
			/* Send response: STK_INSYNC, STK_OK */
			putch(STK_INSYNC);
			putch(STK_OK);
			break;
		}
	
		case CMD_STK_READ_PAGE:
		{
			/* Read the requested memory block and return it back */
			/* Command format: CMD_STK_READ_PAGE, bytes_high, bytes_low, memtype, Sync_CRC_EOP */
			/* Response: Resp_STK_INSYNC, data, Resp_STK_OK */
			int i;
			unsigned int length;
			unsigned long addrPtr;
			UINT8 bytesHigh, bytesLow;
			
			bytesHigh = (UINT8)getch(); /* Get bytes high */
			bytesLow = (UINT8)getch();  /* Get bytes low - number of bytes to read */
			length = ((unsigned int)bytesHigh << 8) | bytesLow;
			getch(); /* Skip mem-type */

			/* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				putch(STK_NOSYNC);
				break;
			}
			
			/* Send INSYNC response */
			putch(STK_INSYNC);
			
			/* Read the requested memory content byte by byte */
			addrPtr = (unsigned long)address;
			for(i = 0; i < length; i++) {
				putch(flash_read_byte(addrPtr++));
			}
			
			/* Update the address pointer for next operation */
			address = (rom unsigned char *)addrPtr;
			
			/* Send final OK status */
			putch(STK_OK);
			break;
		}
		/*case CMD_STK_PROG_FLASH:
			// TODO: Program the device
			sync_ok_response();
			break;*/
		case CMD_STK_READ_SIGN:
		{
			/* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				/* If we don't get the expected marker, send error response */
				putch(STK_NOSYNC);
				break;
			}
			
			putch(STK_INSYNC);
			/* READ SIGN - return what Avrdude wants to hear */
			putch(PROPS_SIGNATURE_H);
			putch(PROPS_SIGNATURE_M);
			putch(PROPS_SIGNATURE_L);    
			putch(STK_OK);
			break;
		}	
		case CMD_STK_SET_DEVICE_EXT:
		{
			/* Set extended device parameters */
			/* Command: commandsize, eeprompagesize, signalpagel, signalbs2, resetdisable, Sync_CRC_EOP */
			/* Read 5 bytes of parameters + EOP = 6 total bytes, then respond with INSYNC+OK */
			getNch(6);
			break;
		}
		case CMD_STK_SET_DEVICE:
		{
			/* Set device programming parameters */
			/* Command takes 20 bytes of parameters + Sync_CRC_EOP */
			/* Response: Resp_STK_INSYNC, Resp_STK_OK */
			getNch(21);
			break;
		}
		case CMD_STK_UNIVERSAL:
		{
			/* The Universal command has 4 command bytes followed by the end marker */
			UINT8 a, b, c, d;
			
			/* Read the 4 command bytes */
			a = getch();
			b = getch();
			c = getch();
			d = getch();
			
			/* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				/* If we don't get the expected marker, send error response */
				putch(STK_NOSYNC);
				break;
			}
			
			/* The correct response format is: STK_INSYNC, result byte, STK_OK */
			putch(STK_INSYNC);
			putch(0x00); /* Return a dummy value 0x00 */
			putch(STK_OK);
			break;
		}
		case CMD_STK_SET_PARAMETER:
		{
			UINT8 param = getch();
			UINT8 value = getch();
			
			/* Verify we get the expected end of command marker (SPECIAL_Sync_CRC_EOP) */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				/* If we don't get the expected marker, send error response */
				putch(STK_NOSYNC);
				break;
			}
			
			/* We just acknowledge without actually setting parameters */
			putch(STK_INSYNC);
			putch(STK_OK);
			break;
		}
		//case CMD_STK_UNIVERSAL_MULTI:
		case CMD_STK_ENTER_PROGMODE:
		case CMD_STK_LEAVE_PROGMODE:
		case CMD_STK_CHIP_ERASE:
		{
			/* These commands just need simple INSYNC+OK response after EOP */
			/* Command format: CMD, Sync_CRC_EOP */
			/* Response: Resp_STK_INSYNC, Resp_STK_OK */
			if (getch() != SPECIAL_Sync_CRC_EOP) {
				putch(STK_NOSYNC);
				break;
			}
			putch(STK_INSYNC);
			putch(STK_OK);
			break;
		}
		default:
		{
			/* For unrecognized commands, we should still read and acknowledge
			 * to prevent the programmer from getting out of sync 
			 * Try to consume the EOP and respond with INSYNC+OK */
			if (getch() == SPECIAL_Sync_CRC_EOP) {
				putch(STK_INSYNC);
				putch(STK_OK);
			} else {
				putch(STK_NOSYNC);
			}
			break;
		}
	}
}