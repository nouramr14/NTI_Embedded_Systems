/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

int main(void)
{
    u16 Local_u16ADC;
    u32 Local_u32mV;
    u32 Local_u32Temperature;

    DIO_voidSetPinDirection(PORTB, PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTA, PIN0, DIO_INPUT);
    DIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN2, DIO_OUTPUT);
    ADC_voidInit();

    while (1)
    {
        Local_u16ADC = ADC_u16Read(ADC_CHANNEL_0);
        Local_u32mV = ((u32)Local_u16ADC * 5000UL) / 1024UL;
        Local_u32Temperature = Local_u32mV / 10UL;

        if (Local_u32Temperature < 20U)
        {
            DIO_voidSetPinValue(PORTC, PIN0, DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN1, DIO_LOW);
            DIO_voidSetPinValue(PORTC, PIN2, DIO_LOW);
            DIO_voidSetPinValue(PORTB, PIN0, DIO_LOW);
        }
        else if (Local_u32Temperature < 40U)
        {
            DIO_voidSetPinValue(PORTC, PIN0, DIO_LOW);
            DIO_voidSetPinValue(PORTC, PIN1, DIO_HIGH);
            DIO_voidSetPinValue(PORTC, PIN2, DIO_LOW);
            DIO_voidSetPinValue(PORTB, PIN0, DIO_LOW);
        }
        else
        {
            DIO_voidSetPinValue(PORTC, PIN0, DIO_LOW);
            DIO_voidSetPinValue(PORTC, PIN1, DIO_LOW);
            DIO_voidSetPinValue(PORTC, PIN2, DIO_HIGH);
            DIO_voidSetPinValue(PORTB, PIN0, DIO_HIGH);
        }
    }
}
