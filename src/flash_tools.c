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

// C function, uses inline assembly (Zilog ZDS-II style)
void programFlashByte(unsigned long addr, unsigned char value) {
    // Unlock and page-select code omitted for brevity...
	if (FCMD != 0x03) return;
    
    // Now program the byte
	// Load 8-bit immediate value AAh into Working Register R2
	// Load the 16-bit immediate value 1400h into Working Register Pair RR6 (R6 and R7)
	// This requires loading the high and low bytes separately,
	// as there is no direct LD instruction for 16-bit immediate to register pair.
	#pragma asm
        LD   R2, 41h ; 'A'
        LD   R6, 14h ; High
		LD	 R7, 00h ; Low
        LDC  @RR6, R2
    #pragma endasm
}

// Read a single byte from flash
unsigned char flash_read_byte(unsigned long addr) {
    // Flash memory is part of Program Memory [2, 4].
    // Reading Program Memory requires the LDC instruction [4, 5, 7].

    
	// LDC r1, @rr2 syntax [9]:
    // r1 = destination register (R0 for return value)
    // @rr2 = source indirect register pair (RR0 holding the address)
    //asm("ldc r0, @rr0  ; Load byte from Program Memory at address in RR0 into R0 [7, 9]");
	#pragma asm
        LD   R2, 41h ; 'A'
        LD   R6, 14h ; High
		LD	 R7, 00h ; Low
        LDC  R0, @RR6
    #pragma endasm

    // The result is now in R0. The compiler automatically handles returning the value in R0.
    // No explicit 'return' statement with a variable assignment is needed here
}


// Read a single byte from flash
//unsigned char flash_read_byte(unsigned long addr) {
    //return *(volatile const char far *)addr;
//}


int someFunction(int a, int b) {
	
	//#pragma asm
	//	ldx r0, (ix+6)
	//	ldx r1, (ix+9)
	//#pragma endasm
    asm("add r0, r1");      // Add r1 to r0, result (0x08) in r0 [13]

    // Move the 8-bit sum from r0 into the L register (R13, part of RR12/HL)
    //asm("ld R13, r0");      // Load R13 with r0 [19, 20] (assuming R13 maps to L)

    // Clear the H register (R12, part of RR12/HL) to make it a 16-bit 0x00xx value
    //asm("ld R12, #0");      // Load R12 with immediate 0 [19, 20] (assuming R12 maps to H)

    // HL (RR12) now holds 0x0008, which is the expected return location [4, 15]
}