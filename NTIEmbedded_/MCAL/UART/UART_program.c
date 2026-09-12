/* Sorry for being late. */

#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_interface.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define UART_BAUD_RATE 9600UL
#define UART_UBRR_VALUE ((F_CPU / (16UL * UART_BAUD_RATE)) - 1UL)

void UART_voidInit(void)
{
    UBRRH = (u8)(UART_UBRR_VALUE >> 8);
    UBRRL = (u8)UART_UBRR_VALUE;

    UCSRB = (1U << RXEN) | (1U << TXEN);
    UCSRC = (1U << URSEL) | (1U << UCSZ1) | (1U << UCSZ0);
}

void UART_voidSendChar(u8 Copy_u8Data)
{
    while (GET_BIT(UCSRA, UDRE) == 0U) {}
    UDR = Copy_u8Data;
}

u8 UART_u8ReceiveChar(void)
{
    while (GET_BIT(UCSRA, RXC) == 0U) {}
    return UDR;
}
