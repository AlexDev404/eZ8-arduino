#pragma once
#define FCMD   (*(volatile unsigned char far *)0x0FF8)  // Define special function register
#define PAGE   (*(volatile unsigned char far *)0x0FF9)  // Page-select byte
#define FFREQH (*(volatile unsigned char far *)0x0FFA)  // Flash Frequency High
#define FFREQL (*(volatile unsigned char far *)0x0FFB)  // Flash Frequency Low

#define WDTCTL (*(volatile unsigned char far *)0x0FF0)  // Watchdog timer control (Write-only)
#define WDTU   (*(volatile unsigned char far *)0x0FF1)  // Watchdog Timer Reload Upper Byte
#define WDTH   (*(volatile unsigned char far *)0x0FF2)  // Watchdog Timer Reload High Byte
#define WDTL   (*(volatile unsigned char far *)0x0FF3)  // Watchdog Timer Reload Low Byte

// Function to unlock the flash controller
void unlockFlash(void);

// Function to unlock the watchdog timer and reset the device
void reset_device(void);

// Function to check the current status of the flash controller
unsigned char checkFlash(void);

// Function to erase the flash page containing the specified address
// Returns 0 on success, nonzero if failed
int pageEraseFlash(unsigned long address);

// Function to erase the entire flash
void massEraseFlash(void);

// Function to write a byte to the flash memory (after an unlock)
int programFlashByte(unsigned long addr, unsigned char data);

unsigned char flash_read_byte(unsigned long addr);

void setFlashFreq(unsigned int systemClockKhz);

int someFunction(int a, int b);