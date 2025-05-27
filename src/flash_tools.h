#pragma once
#define FCMD (*(volatile unsigned char far *)0x0FF8)  // Define special function register
#define PAGE (*(volatile unsigned char far *)0x0FF9)

// Function to unlock the flash controller
void unlockFlash(void);

// Function to check the current status of the flash controller
unsigned char checkFlash(void);

// Function to erase the flash page containing the specified address
// Returns 0 on success, nonzero if failed
int pageEraseFlash(unsigned long address);

// Function to erase the entire flash
void massEraseFlash(void);