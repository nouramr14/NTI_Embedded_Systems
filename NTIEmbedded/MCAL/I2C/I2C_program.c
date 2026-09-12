/* Sorry for being late. */

#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "I2C_interface.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

void I2C_voidInit(void)
{
    /* 100 kHz at 8 MHz CPU clock, prescaler = 1. */
    TWSR = 0x00;
    TWBR = 32;
    TWCR = (1U << TWEN);
}

void I2C_voidStart(void)
{
    TWCR = (1U << TWINT) | (1U << TWSTA) | (1U << TWEN);
    while (!(TWCR & (1U << TWINT))) {}
}

void I2C_voidStop(void)
{
    TWCR = (1U << TWINT) | (1U << TWSTO) | (1U << TWEN);
}

void I2C_voidWrite(u8 Copy_u8Data)
{
    TWDR = Copy_u8Data;
    TWCR = (1U << TWINT) | (1U << TWEN);
    while (!(TWCR & (1U << TWINT))) {}
}

u8 I2C_u8ReadAck(void)
{
    TWCR = (1U << TWINT) | (1U << TWEN) | (1U << TWEA);
    while (!(TWCR & (1U << TWINT))) {}
    return TWDR;
}

u8 I2C_u8ReadNack(void)
{
    TWCR = (1U << TWINT) | (1U << TWEN);
    while (!(TWCR & (1U << TWINT))) {}
    return TWDR;
}
