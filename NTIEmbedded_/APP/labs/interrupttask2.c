/* Sorry for being late. */

#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"

volatile s8 g_s8Direction = 1;

int main(void)
{
    u8 Local_u8CurrentLed = 0;

    DIO_voidSetPortDirection(PORTC, 0xFF);
    DIO_voidSetPinDirection(PORTB, PIN2, DIO_INPUT);
    DIO_voidSetPinValue(PORTB, PIN2, DIO_HIGH);

    EXTI_voidSetSenseControl(EXTI_INT2, EXTI_FALLING_EDGE);
    EXTI_voidEnable(EXTI_INT2);
    sei();

    while (1)
    {
        DIO_voidSetPortValue(PORTC, (u8)(1U << Local_u8CurrentLed));
        for (volatile u32 i = 0; i < 30000UL; i++) {}

        Local_u8CurrentLed = (u8)(Local_u8CurrentLed + g_s8Direction);
        if (Local_u8CurrentLed > 7U)
            Local_u8CurrentLed = 0U;
    }
}

ISR(INT2_vect)
{
    g_s8Direction = -g_s8Direction;
}
