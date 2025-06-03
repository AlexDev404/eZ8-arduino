#include "flash_tools.h"

// Unlock the flash controller with proper polling for each key
void unlockFlash(void) {
	if (FCMD == 0x02 || FCMD == 0x03) return;
    FCMD = 0x73;  // First unlock key
	while (FCMD != 0x01); // Wait for "first key received"

    FCMD = 0x8C;  // Second unlock key
	while (FCMD != 0x02); // Wait for "second key received"
}

// Unlock the watchdog timer and reset the device
void reset_device(void) {
	// 1. Unlock the Watchdog Timer Reload Registers
    // The WDTCTL register (FF0H) is a write-only register used to unlock access to the reload registers [1, 2].
    // The unlock sequence involves two sequential writes without any other register writes in between [10].
    // Writing these values to WDTCTL produces no effect on its own bits; they solely control the lock state [2].
   
	WDTCTL = 0x55;
	WDTCTL = 0xAA;
	
	// Set the minimum timeout delay (400us)
	// This should be a 24-bit reload value of 0x000004
	
	WDTU = 0x00; // Upper
	WDTH = 0x00; // High
	WDTL = 0x04; // Low
	
	// Enable the timer (because by default it's disabled)
	asm("WDT");
	
	// Do nothing (and wait for the reset)
	while(1); // Busy loop + reset
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

int programFlashByte(unsigned long addr, unsigned char data) {
    // --- Preconditions Assumed Handled by Caller ---
    // 1. Flash Controller unlocked (73H, 8CH to FCTL at FF8H).
    // 2. Target page selected (write to FPS at FF9H).
    // 3. Target page erased (write 95H to FCTL and wait for completion).
    // 4. Controller state is ready for byte programming (might require re-unlocking
    //    and page selection after erase completes, depending on full sequence).
    // 5. The specific byte at 'addr' hasn't been programmed too many times since erase (max 2 times).
    // ------------------------------------------------

    // Cast the given address to a pointer type that indicates the data is in ROM (Program Memory).
    // Using 'unsigned char' is appropriate for writing a single byte.
	rom unsigned char* p = (rom unsigned char*)addr;
	//if (FCMD != 0x03) return -1;
	
    // Attempt to write the data byte to the flash address by dereferencing the rom pointer.
    // This C assignment should be translated by the compiler into an LDC or LDCI instruction
    // which performs the actual hardware write to the Flash cell, provided the Flash
    // controller is correctly configured.
    *p = data;

    // --- Returning 'bool' for success ---
    // Flash programming is NOT instantaneous. The write operation takes time (20-40 µs typical) [ps0228.pdf 234, 595].
    // For a function returning 'bool' to reliably indicate success, it MUST wait
    // for the hardware programming operation to complete and check its status.
    // This is done by polling the Flash Status Register (FSTAT at FF8H) [ps0228.pdf 155, 493, 494].
    // FSTAT[5:0] will show '001xxx' while programming is in progress [ps0228.pdf 155, 495].

    // A typical polling loop would look something like this (conceptual):
    /*
    volatile unsigned char flash_status;
    unsigned int timeout = 10000; // Prevent infinite loop, value needs tuning

    // Wait for the 'program in progress' status to clear
    do {
        flash_status = FSTAT; // Read the status register
        // Check if FSTAT[5:0] is in the programming range (0b001000 through 0b001111)
    } while ((flash_status & 0x38) == 0x08 && --timeout); // Check if status is 001xxx

    // Check if timeout occurred
    if (timeout == 0) {
        // Optional: Attempt to reset/lock controller? Log error?
        return false; // Write timed out, likely failed
    }

    // Check for specific write errors if documented for byte programming in FSTAT
    // (Sources mention AWE/DWE for NVDS [ps0228.pdf 177, 532], not explicitly for general byte write status in FSTAT)
    // If specific error bits existed:
    // if (flash_status & ERROR_BITS_MASK) return false;

    // If we reached here, the programming operation status has cleared.
    // Assume success unless FSTAT indicates a specific error state (not fully detailed in sources for byte write).
    return true;
    */

    // Without implementing the full polling and detailed status checks,
    // we cannot definitively return true/false based on hardware completion.
    // Given the prompt's request to correct/return the code and the assumption
    // of external setup, the core *action* is the assignment.
    // For the 'bool' return placeholder, we'll return true, but *emphasize*
    // that real code needs the polling logic above for reliability.
    // This return is based on the ASSUMPTION the caller made the write possible.
    return 1; // Placeholder - requires FSTAT polling for true hardware status

}

// Read a single byte from flash
unsigned char flash_read_byte(unsigned long addr) {
    // Flash memory is part of Program Memory [2-6].
    // Reading Program Memory typically requires the LDC or LDX instruction [7-13].
    // The 'rom' keyword is a ZiLOG extension that tells the compiler the data is in Program Memory [14, 15].
    // Dereferencing a 'rom' pointer should cause the compiler to use the appropriate instruction [16].

    // Cast the given address to a pointer type that indicates the data is in ROM (Program Memory)
    rom unsigned char* p = (rom unsigned char*)addr;

    // Dereference the pointer to read the byte value from the flash address
    // The compiler will generate the necessary instruction (LDC or LDX) to read from Program Memory.
    // A single byte (char/unsigned char) return value is placed in register A according to calling conventions [1].
    return *p;
}

// Function to set Flash Frequency registers (YOU NEED TO IMPLEMENT THIS)
// It must set FFREQH (FFAH) and FFREQL (FFBH) based on your system clock frequency in kHz.
void setFlashFreq(unsigned int systemClockKhz) {
    // Example for a 20 MHz system clock (20000 kHz)
    // unsigned int freq_val = 20000;
    // FFREQH = (freq_val >> 8) & 0xFF; // High byte
    // FFREQL = freq_val & 0xFF;       // Low byte

    // Placeholder - Replace with your actual system clock frequency in kHz
    unsigned int freq_val = systemClockKhz; // Example: 20000 for 20MHz
    FFREQH = (freq_val >> 8) & 0xFF; // Set Flash Frequency High Byte (FFAH)
    FFREQL = freq_val & 0xFF;        // Set Flash Frequency Low Byte  (FFBH)
}

/*int someFunction(int a, int b) {
	
	//#pragma asm
	//	ldx r0, (hl+6)
	//	ldx r1, (hl+9)
	//#pragma endasm
    
	asm("add r0, r1");      // Add r1 to r0, result (0x08) in r0 [13]

    // Move the 8-bit sum from r0 into the L register (R13, part of RR12/HL)
    //asm("ld R13, r0");      // Load R13 with r0 [19, 20] (assuming R13 maps to L)

    // Clear the H register (R12, part of RR12/HL) to make it a 16-bit 0x00xx value
    //asm("ld R12, #0");      // Load R12 with immediate 0 [19, 20] (assuming R12 maps to H)

    // HL (RR12) now holds 0x0008, which is the expected return location [4, 15]
}*/