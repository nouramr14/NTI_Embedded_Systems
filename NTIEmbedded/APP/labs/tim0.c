/* Sorry for being late. */

#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"

static void TIMER0_ISR(void)
{
    static u8 Local_u8OverflowCount = 0;
    static u8 Local_u8LedState = DIO_LOW;

    Local_u8OverflowCount++;

    if (Local_u8OverflowCount == 30)
    {
        TIMER0_voidSetPreload(124);
    }
    else if (Local_u8OverflowCount > 30)
    {
        Local_u8LedState = !Local_u8LedState;
        DIO_voidSetPinValue(PORTA, PIN0, Local_u8LedState);
        Local_u8OverflowCount = 0;
        TIMER0_voidSetPreload(0);
    }
}

int main(void)
{
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(PORTA, PIN0, DIO_LOW);

    TIMER0_voidSetCallback(TIMER0_ISR);
    TIMER0_voidInitNormal();
    sei();

    while (1) {}
}
