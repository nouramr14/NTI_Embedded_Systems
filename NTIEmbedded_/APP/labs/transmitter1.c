/* Sorry for being late. */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"

int main(void)
{
    UART_voidInit();
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_OUTPUT);

    while (1)
    {
        UART_voidSendChar('1');
        _delay_ms(1000);
    }
}
