/* Sorry for being late. */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    while (1)
    {
        DIO_voidSetPinValue(PORTC, PIN0, DIO_HIGH);
        _delay_ms(3000);
        DIO_voidSetPinValue(PORTC, PIN0, DIO_LOW);
        _delay_ms(3000);
    }
}
