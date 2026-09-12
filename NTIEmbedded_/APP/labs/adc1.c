/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

int main(void)
{
    u16 Local_u16ADC = 0;
    u32 Local_u32mV = 0;

    DIO_voidSetPinDirection(PORTA, PIN0, DIO_INPUT);
    ADC_voidInit();

    while (1)
    {
        Local_u16ADC = ADC_u16Read(ADC_CHANNEL_0);
        Local_u32mV = ((u32)Local_u16ADC * 5000UL) / 1024UL;
        (void)Local_u32mV;
    }
}
