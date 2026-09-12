/* Sorry for being late. */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_CTC_interface.h"

static void (*g_TIMER0_CTC_pvCallback)(void) = 0;

void TIMER0_CTC_voidInit(void)
{
    /* CTC mode, toggle/output action handled by callback, prescaler = 1024. */
    TCCR0 = 0x00;
    SET_BIT(TCCR0, WGM01);
    CLR_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    SET_BIT(TIMSK, OCIE0);
}

void TIMER0_CTC_voidSetCompareValue(u8 Copy_u8CompareValue)
{
    OCR0 = Copy_u8CompareValue;
}

void TIMER0_CTC_voidSetCallback(void (*Copy_pvCallback)(void))
{
    g_TIMER0_CTC_pvCallback = Copy_pvCallback;
}

ISR(TIMER0_COMP_vect)
{
    if (g_TIMER0_CTC_pvCallback != 0) g_TIMER0_CTC_pvCallback();
}
