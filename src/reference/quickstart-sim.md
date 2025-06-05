# To test (spoofed)

```
#define PROPS_SIGNATURE_H 0x1E
#define PROPS_SIGNATURE_M 0x95
#define PROPS_SIGNATURE_L 0x0F
```

```
avrdude -CC:\Users\Immanuel\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -v -patmega328p -carduino -PCOM5 -b115200 -D -Uflash:w:C:\Data\zilog\XP_F082A_uART\src\reference\Test.BareMinimum.ino.hex:i
```

# To test (non-spoofed)

```
#define PROPS_SIGNATURE_H 0x73
#define PROPS_SIGNATURE_M 0xFF
#define PROPS_SIGNATURE_L 0x96
```

```
avrdude -CC:\Data\zilog\XP_F082A_uART\src\avrdude.conf -v -pz8f081a_no_nvds -carduino -PCOM5 -b115200 -D -Uflash:w:C:\Data\zilog\XP_F082A_uART\src\reference\Test.BareMinimum.ino.hex:i
```