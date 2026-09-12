/* Sorry for being late. */

#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "SPI_interface.h"

void SPI_voidInit(void)
{
#if SPI_MODE == SPI_MASTER
    DIO_voidSetPinDirection(PORTB, PIN4, DIO_OUTPUT); /* SS */
    DIO_voidSetPinDirection(PORTB, PIN5, DIO_OUTPUT); /* MOSI */
    DIO_voidSetPinDirection(PORTB, PIN6, DIO_INPUT);  /* MISO */
    DIO_voidSetPinDirection(PORTB, PIN7, DIO_OUTPUT); /* SCK */
    DIO_voidSetPinValue(PORTB, PIN4, DIO_HIGH);
    SPCR = (1U << SPE) | (1U << MSTR) | (1U << SPR0);
#else
    DIO_voidSetPinDirection(PORTB, PIN4, DIO_INPUT);
    DIO_voidSetPinDirection(PORTB, PIN5, DIO_INPUT);
    DIO_voidSetPinDirection(PORTB, PIN6, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTB, PIN7, DIO_INPUT);
    SPCR = (1U << SPE);
#endif
}

void SPI_voidSendChar(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    while (GET_BIT(SPSR, SPIF) == 0U) {}
}

u8 SPI_u8GetChar(void)
{
    while (GET_BIT(SPSR, SPIF) == 0U) {}
    return SPDR;
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    while (GET_BIT(SPSR, SPIF) == 0U) {}
    return SPDR;
}
