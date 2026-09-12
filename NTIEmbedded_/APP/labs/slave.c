/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"

int main(void)
{
    u8 Local_u8ReceivedData;
    SPI_voidInit();
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_OUTPUT);

    while (1)
    {
        Local_u8ReceivedData = SPI_u8GetChar();
        if (Local_u8ReceivedData == '1')
        {
            u8 Local_u8State = DIO_u8ReadPinValue(PORTA, PIN0);
            DIO_voidSetPinValue(PORTA, PIN0, Local_u8State ? DIO_LOW : DIO_HIGH);
        }
    }
}
