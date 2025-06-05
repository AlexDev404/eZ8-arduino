# eZ8-arduino

Mostly testing for eZ80 to see if I can write a working STK200v1 bootloader onto it.

---

## Requirements

- Arduino IDE
- ZDS II Development IDE
- 1× Z8F082A chip
- 1× Zilog Encore! Smart Cable
- Lots of Dupont jumper wires
- 1× USB Male-to-Male breadboard power supply
- 2× breadboards
- Headers to fit the 2×3 debug header
- 2× 10K resistors
- 1× LED (any color)
- 1× FTDI Adapter ([Amazon link](https://amzn.to/459oyPt))

---

## Breadboard Setup

### 1. Main Breadboard

Set up your first breadboard to match this schematic:

![First breadboard schematic](https://github.com/user-attachments/assets/5b9c4453-960e-4375-94ff-60c94400f41a)

For more details, see [official documentation (UM0294)](https://www.zilog.com/docs/devtools/UM0294.pdf).

---

### 2. Chip Breadboard

- Place the Z8F082A chip in the middle of the second breadboard.
- Connect the first setup to the chip as shown in the [chip specifications, pg 25](https://www.zilog.com/docs/z8encorexp/ps0228.pdf):

![Chip connection schematic](https://github.com/user-attachments/assets/52e8841c-906c-403f-86c0-d8cd12ead21d)

- Match up the pins:
  - **DBG (P15)**
  - **RESET (P14)**
  - (T_MSG isn't required)
- Connect power to the chip:
  - **VDD (POS/P4)**
  - **VSS (NEG/P7)**
- **Do not connect 5V to the chip.** Connect the breadboard power supply (3V) to the power rails.

---

## FTDI UART Connection

> [!TIP]  
> After all wiring, connect the FTDI adapter to the chip as follows:  
> **RX → TX, TX → RX, CTS → CTS**

---

## LED Connection

> [!IMPORTANT]  
> Double-check LED polarity. Reversed connections may prevent the LED from lighting up or could damage components.

- Place an LED on your breadboard.
- Connect the **cathode** to **pin 19** of the chip.
- Connect the **anode** to ground.

---

## Load the Project

> [!WARNING]  
> Incorrect wiring or flashing will permanently damage your chip.
>
> Absolutely do **NOT** overwrite the first two bits of the flash with zeros otherwise it will be permanently disabled.
>
> Proceed with care!

1. Set up the ZDS II IDE on your computer.
2. Open the project from this repository.
3. Open a command line in the directory containing `avrdude` (typically `{Arduino_ROOT}\hardware\tools\avr\bin`).
4. Run one of the commands listed in [`./references/quickstart-sim.md`](./references/quickstart-sim.md), depending on the chip signature found in [`./src/stk500.h`](./src/stk500.h).

---

## Final Notes

- Try uploading a hex file to the chip.
- In ZDS II, you can view the chip's memory by pausing execution and going to "Memory".
- Check if the chip successfully wrote to memory at address `0x1000`.

Good luck!
