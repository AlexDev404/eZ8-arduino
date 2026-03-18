# Testing with avrdude

## CRITICAL: Disable DEBUG_BANNER and ECHO_TEST_MODE before using avrdude!

If you enabled debugging features for testing, you MUST disable them before using avrdude:
1. In `src/main.c`, ensure `#define DEBUG_BANNER 0`
2. In `src/main.c`, ensure `#define ECHO_TEST_MODE 0`
3. Rebuild and reflash the bootloader
4. Debug output interferes with the STK500 protocol

## Diagnostic: Echo Test Mode

If avrdude fails but the debug banner works, use echo test to verify RX works:

1. Set `ECHO_TEST_MODE` to 1 in `src/main.c`
2. Rebuild and reflash
3. Open terminal at 115200 baud
4. On reset, you should see: `ECHO: `
5. Type characters - each will echo as `[XX]` where XX is hex value
6. Type `0` - should show `[30]` (this is CMD_STK_GET_SYNC)
7. Type ` ` (space) - should show `[20]` (this is CRC_EOP)

If echo test works correctly, both RX and TX are functional.

## Test command (spoofed as ATmega328P)

Use these signature values in `include/stk500.h`:
```c
#define PROPS_SIGNATURE_H 0x1E
#define PROPS_SIGNATURE_M 0x95
#define PROPS_SIGNATURE_L 0x0F
```

Then run avrdude with **115200 baud**:
```
avrdude -CC:\Users\Immanuel\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -v -patmega328p -carduino -PCOM5 -b115200 -D -Uflash:w:C:\Data\zilog\XP_F082A_uART\src\reference\Test.BareMinimum.ino.hex:i
```

## Test command (non-spoofed, custom avrdude.conf)

Use these signature values in `include/stk500.h`:
```c
#define PROPS_SIGNATURE_H 0x73
#define PROPS_SIGNATURE_M 0xFF
#define PROPS_SIGNATURE_L 0x96
```

```
avrdude -CC:\Data\zilog\XP_F082A_uART\src\avrdude.conf -v -pz8f081a_no_nvds -carduino -PCOM5 -b115200 -D -Uflash:w:C:\Data\zilog\XP_F082A_uART\src\reference\Test.BareMinimum.ino.hex:i
```

# Important Notes

- **Baud rate**: The bootloader uses **115200 baud**. You MUST use `-b115200` with avrdude.
- **DEBUG_BANNER must be disabled**: If you see "STK500" in terminal but avrdude fails, the debug banner is interfering. Rebuild with `DEBUG_BANNER 0`.
- **Random garbage (0xXX)**: Indicates baud rate mismatch. Verify you're using `-b115200`.
- **Oscillator variation**: If garbage persists, try adjusting `SYSTEM_CLOCK_HZ` in `uart.c`.

# Troubleshooting Checklist

1. **DEBUG_BANNER is disabled** (set to 0 in main.c)
2. **Using `-b115200`** with avrdude (NOT `-b9600`)
3. **TX/RX wired correctly**: FTDI TX → Z8 RX, FTDI RX → Z8 TX
4. **CTS connected** if required by FTDI adapter
5. **Power supply stable** (3.3V)
6. **Reset chip** before running avrdude (or add auto-reset circuit)