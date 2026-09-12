/* Sorry for being late. */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../HAL/LCD/LCD_interface.h"

int main(void)
{
    u16 Local_u16DigitalValue;
    u32 Local_u32InputVoltage;

    DIO_voidSetPinDirection(PORTA, PIN0, DIO_INPUT);
    ADC_voidInit();
    LCD_voidInit();
    LCD_voidGoToXY(0, 0);
    LCD_voidSendString((const u8 *)"Volt: ");

    while (1)
    {
        Local_u16DigitalValue = ADC_u16Read(ADC_CHANNEL_0);
        Local_u32InputVoltage = ((u32)Local_u16DigitalValue * 5000UL) / 1024UL;
        LCD_voidGoToXY(6, 0);
        LCD_voidWriteNumber((s32)Local_u32InputVoltage);
        LCD_voidSendString((const u8 *)" mV   ");
        _delay_ms(1000);
    }
}
