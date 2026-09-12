/* Sorry for being late. */

# NTI Training - HAL / MCAL layered implementation

The project was reorganized into a simple AVR layered architecture:

- `LIB/` — standard types and bit manipulation macros.
- `MCAL/` — low-level MCU peripherals: DIO, ADC, UART, SPI, I2C, EXTI, Timer0 and Timer0 CTC.
- `HAL/` — hardware abstraction drivers: LCD, Keypad and Stepper Motor.
- `APP/` — applications, separated into `labs/` and `assignments/`.

## Build model

For each application, compile:
1. The selected application `.c` file.
2. All required MCAL/HAL `.c` files.
3. With AVR-GCC for the target MCU (the code targets ATmega32).

Do not compile multiple application files into one firmware image because each application contains its own `main()`.

## Important fixes made

- Removed direct register access from application files.
- Split drivers into interface and program files.
- Fixed the EXTI header/API mismatch.
- Added the missing Timer0 CTC driver used by `timpot.c`.
- Moved keypad scanning into the HAL instead of implementing a second keypad driver inside an assignment.
- Kept the original training exercises as separate applications.
- Added the requested `APP/labs` and `APP/assignments` folders.
