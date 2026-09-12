/* Sorry for being late. */

#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTD, PIN2, DIO_INPUT);
    DIO_voidSetPinDirection(PORTD, PIN3, DIO_INPUT);

    EXTI_voidInit();
    while (1) {}
}

ISR(INT0_vect)
{
    DIO_voidSetPinValue(PORTC, PIN0,
        DIO_u8ReadPinValue(PORTC, PIN0) ? DIO_LOW : DIO_HIGH);
}

ISR(INT1_vect)
{
    DIO_voidSetPinValue(PORTC, PIN1,
        DIO_u8ReadPinValue(PORTC, PIN1) ? DIO_LOW : DIO_HIGH);
}
