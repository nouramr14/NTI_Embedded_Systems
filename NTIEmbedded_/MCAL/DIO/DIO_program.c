/* Sorry for being late. */

#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    if (Copy_u8Port > PORTD || Copy_u8Pin > PIN7) return;

    volatile u8 *Local_pu8DDR = 0;

    switch (Copy_u8Port)
    {
        case PORTA: Local_pu8DDR = &DDRA; break;
        case PORTB: Local_pu8DDR = &DDRB; break;
        case PORTC: Local_pu8DDR = &DDRC; break;
        case PORTD: Local_pu8DDR = &DDRD; break;
        default: return;
    }

    if (Copy_u8Direction == DIO_OUTPUT) SET_BIT(*Local_pu8DDR, Copy_u8Pin);
    else if (Copy_u8Direction == DIO_INPUT) CLR_BIT(*Local_pu8DDR, Copy_u8Pin);
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if (Copy_u8Port > PORTD || Copy_u8Pin > PIN7) return;

    volatile u8 *Local_pu8PORT = 0;

    switch (Copy_u8Port)
    {
        case PORTA: Local_pu8PORT = &PORTA; break;
        case PORTB: Local_pu8PORT = &PORTB; break;
        case PORTC: Local_pu8PORT = &PORTC; break;
        case PORTD: Local_pu8PORT = &PORTD; break;
        default: return;
    }

    if (Copy_u8Value == DIO_HIGH) SET_BIT(*Local_pu8PORT, Copy_u8Pin);
    else if (Copy_u8Value == DIO_LOW) CLR_BIT(*Local_pu8PORT, Copy_u8Pin);
}

u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    if (Copy_u8Port > PORTD || Copy_u8Pin > PIN7) return DIO_LOW;

    volatile u8 *Local_pu8PIN = 0;

    switch (Copy_u8Port)
    {
        case PORTA: Local_pu8PIN = &PINA; break;
        case PORTB: Local_pu8PIN = &PINB; break;
        case PORTC: Local_pu8PIN = &PINC; break;
        case PORTD: Local_pu8PIN = &PIND; break;
        default: return DIO_LOW;
    }

    return GET_BIT(*Local_pu8PIN, Copy_u8Pin);
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    volatile u8 *Local_pu8DDR = 0;
    switch (Copy_u8Port)
    {
        case PORTA: Local_pu8DDR = &DDRA; break;
        case PORTB: Local_pu8DDR = &DDRB; break;
        case PORTC: Local_pu8DDR = &DDRC; break;
        case PORTD: Local_pu8DDR = &DDRD; break;
        default: return;
    }
    *Local_pu8DDR = Copy_u8Direction;
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    volatile u8 *Local_pu8PORT = 0;
    switch (Copy_u8Port)
    {
        case PORTA: Local_pu8PORT = &PORTA; break;
        case PORTB: Local_pu8PORT = &PORTB; break;
        case PORTC: Local_pu8PORT = &PORTC; break;
        case PORTD: Local_pu8PORT = &PORTD; break;
        default: return;
    }
    *Local_pu8PORT = Copy_u8Value;
}

u8 DIO_u8ReadPortValue(u8 Copy_u8Port)
{
    switch (Copy_u8Port)
    {
        case PORTA: return PINA;
        case PORTB: return PINB;
        case PORTC: return PINC;
        case PORTD: return PIND;
        default: return 0;
    }
}
