/* Sorry for being late. */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_interface.h"

static void (*g_TIMER0_pvCallback)(void) = 0;

void TIMER0_voidInitNormal(void)
{
    TCCR0 = 0x00;
    TCNT0 = 0x00;
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02); /* F_CPU/1024 */
    SET_BIT(TIMSK, TOIE0);
}

void TIMER0_voidSetPreload(u8 Copy_u8Preload)
{
    TCNT0 = Copy_u8Preload;
}

void TIMER0_voidSetCallback(void (*Copy_pvCallback)(void))
{
    g_TIMER0_pvCallback = Copy_pvCallback;
}

ISR(TIMER0_OVF_vect)
{
    if (g_TIMER0_pvCallback != 0) g_TIMER0_pvCallback();
}
