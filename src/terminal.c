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
			    */
		       //UINT16 newAddress;
		       //newAddress = getch();
		       //newAddress = (newAddress & 0xff) | (getch() << 8);
		       //newAddress += newAddress; /* Convert from word address to byte address */
		       //address = (rom unsigned char*)newAddress;
		       //sync_ok_response();
			   getNch(3);
			   putch(STK_INSYNC);  // Dumb protocol has me have this extra bit here.
			   putch(STK_OK);
			   getNch(3);
			   putch(STK_INSYNC);  // Dumb protocol has me have this extra bit here.
			   putch(STK_OK);
			   break;
			}
		case CMD_STK_PROG_PAGE:
		{
			/* Program a page, length in big endian and in bytes */
			/* We don't need a buffer since this chip supports byte-programming :D */
			unsigned long addrPtr;
			unsigned int i, z = 0;
			
			/* Send INSYNC response */	
			putch(STK_INSYNC);
			
			getch(); /* Skip bytes high */
			i = (unsigned char)getch(); /* Content-Length of data in bytes (UNSIGNED... please+thanks) */
			getch(); /* Skip memtype (usually 'F' 0x46 for FLASH) */
					
			/* Calculate the page address (start of page containing the target address) */
			addrPtr = (unsigned long)address;
			/* Save where we'll stop */
			address = (rom unsigned char *)(addrPtr + i);
			
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
				getch();
				while (FCMD != 0x03);
				addrPtr++;
			}			
			
			getch(); /* Consume the end marker (SPECIAL_Sync_CRC_EOP) */
			/* Send OK status */
			putch(STK_OK);
			break;
		}
	
		case CMD_STK_READ_PAGE:
		{
			/* Read the requested memory block and return it back */
			int i, z = 0;
			unsigned long addrPtr;
			
			getch(); /* Skip bytes-high */
			z = (unsigned char)getch(); /* Bytes-low - number of bytes to read */
			getch(); /* Skip mem-type */

			/* Send INSYNC response */
			getch(); /* Consume the end marker (SPECIAL_Sync_CRC_EOP) */	
			putch(STK_INSYNC);
			
			/* Read the requested memory content byte by byte */
			addrPtr = (unsigned long)address;
			for(i = 0; i < z; i++) {
				putch(flash_read_byte(addrPtr++));
			}
			
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
		case CMD_STK_SET_DEVICE_EXT:
		{
			getNch(7);
			break;
		}
		case CMD_STK_SET_DEVICE:
		case CMD_STK_SET_DEVICE:
		{
			getNch(21);
			putch(STK_INSYNC);  // Really random. I don't know why it's this way
			putch(STK_OK);
			reset_device();
			break;
		}
		// case CMD_STK_SET_DEVICE:
		// {
		// 	/* According to STK500 protocol, this command has 20 device parameters:
		// 	 * DeviceCode, Revision, ProgType, ParamMode, Polling, SelfTimed, LockBytes,
		// 	 * FuseBytes, FlashPollVal1, FlashPollVal2, EepromPollVal1, EepromPollVal2,
		// 	 * PageSize, EepromSize, FlashSize4, FlashSize3, FlashSize2, FlashSize1,
		// 	 * ExtParams, HvspParams
		// 	 * We need to skip over all of them and acknowledge
		// 	 */
		// 	getNch(20); /* Discard the 20 device parameters */
		// 	break;
		// }
		// case CMD_STK_SET_DEVICE_EXT:
		// {
		// 	/* According to STK500 protocol, this command has 5 extended parameters:
		// 	 * CommandSize, EepromPageSize, SignatureBytes, ResetDisable, Wdton
		// 	 */
		// 	getNch(5);
		// 	break;
		// }
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
		//case CMD_STK_ENTER_PROGMODE:
		//case CMD_STK_LEAVE_PROGMODE:
		//case CMD_STK_CHIP_ERASE:
		default:
		{
			/* For unrecognized commands, we should still read and acknowledge
			 * to prevent the programmer from getting out of sync */
			getch(); /* Consume the end marker */
			putch(STK_INSYNC);
			putch(inputch);
			//putch(STK_OK);
			//reset_device();
			break;
		}
	}
}