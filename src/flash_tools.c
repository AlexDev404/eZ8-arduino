#include "flash_tools.h"

// Unlock the flash controller with proper polling for each key
void unlockFlash(void) {
	if (FCMD == 0x02 || FCMD == 0x03) return;
    FCMD = 0x73;  // First unlock key
	while (FCMD != 0x01); // Wait for "first key received"

    FCMD = 0x8C;  // Second unlock key
	while (FCMD != 0x02); // Wait for "second key received"
}

// Return the Flash Controller Status
unsigned char checkFlash(void) {
    return FCMD;
}

int pageEraseFlash(unsigned long address) {
	unsigned char pageNum;
	int i = 0;
	
	if (FCMD == 0x03) return -1;
	
	// Calculate page number from address (512-byte pages)
	pageNum = (unsigned char)((address >> 9) & 0xFF);
	
	// According to the flow diagram in PS0228 and AN0328
	for (i = 0; i < 1; i++) {
		// Set page number for erase
		PAGE = pageNum;
		// Unlock Flash
		unlockFlash();
		// Set page number for erase
		PAGE = pageNum;
		// Erase
		FCMD = 0x95;
	}
	
	// Wait for erase to complete (status returns to 0)
	while (FCMD != 0x00);	
	
	///////// UNLOCK THE PAGE ///////////
	
	// Set page number for erase
	PAGE = pageNum;

	// Unlock Flash
	unlockFlash();
	
	// Set page number for erase
	PAGE = pageNum;
	
	
    // Todo: Optionally, verify erased (all 0xFF) here
	//if (FCMD == 0x00) return -1;
	// Wait for unlock to complete (status returns to 3)
	while (FCMD != 0x03);
	return 0; // Success
}

void massEraseFlash(void) {
	if (FCMD == 0x03) return;
    FCMD = 0x63; // Mass Erase command
    while (FCMD != 0x03); // Wait until erase completes (status returns to 0)
}
