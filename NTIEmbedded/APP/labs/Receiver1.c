/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"

int main(void)
{
    u8 Local_u8ReceivedData;
    UART_voidInit();
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_OUTPUT);

    while (1)
    {
        Local_u8ReceivedData = UART_u8ReceiveChar();
        if (Local_u8ReceivedData == '1')
            DIO_voidSetPinValue(PORTA, PIN0, DIO_HIGH);
        else
            DIO_voidSetPinValue(PORTA, PIN0, DIO_LOW);
    }
}
