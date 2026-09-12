/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_INPUT);
    DIO_voidSetPinDirection(PORTA, PIN1, DIO_INPUT);
    DIO_voidSetPinDirection(PORTA, PIN2, DIO_INPUT);
    DIO_voidSetPinDirection(PORTA, PIN7, DIO_INPUT);

    DIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN2, DIO_OUTPUT);

    while (1)
    {
        if (DIO_u8ReadPinValue(PORTA, PIN7) == DIO_LOW)
        {
            DIO_voidSetPinValue(PORTC, PIN0, DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN1, DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN2, DIO_HIGH);
        }
        else
        {
            DIO_voidSetPinValue(PORTC, PIN0, DIO_u8ReadPinValue(PORTA, PIN0) ? DIO_LOW : DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN1, DIO_u8ReadPinValue(PORTA, PIN1) ? DIO_LOW : DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN2, DIO_u8ReadPinValue(PORTA, PIN2) ? DIO_LOW : DIO_HIGH);
        }
    }
}
