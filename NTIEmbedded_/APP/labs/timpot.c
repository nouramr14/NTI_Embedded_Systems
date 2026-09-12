/* Sorry for being late. */

#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/TIMER0_CTC/TIMER0_CTC_interface.h"

static void TIMER0_CompareMatch_ISR(void)
{
    static u8 Local_u8LedState = DIO_LOW;
    Local_u8LedState = !Local_u8LedState;
    DIO_voidSetPinValue(PORTB, PIN0, Local_u8LedState);
}

int main(void)
{
    u16 Local_u16ADC;
    u8 Local_u8CompareValue;

    DIO_voidSetPinDirection(PORTB, PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(PORTB, PIN0, DIO_LOW);

    ADC_voidInit();
    TIMER0_CTC_voidSetCallback(TIMER0_CompareMatch_ISR);
    TIMER0_CTC_voidInit();
    sei();

    while (1)
    {
        Local_u16ADC = ADC_u16Read(ADC_CHANNEL_0);
        Local_u8CompareValue = (u8)(Local_u16ADC >> 2);
        TIMER0_CTC_voidSetCompareValue(Local_u8CompareValue);
    }
}
