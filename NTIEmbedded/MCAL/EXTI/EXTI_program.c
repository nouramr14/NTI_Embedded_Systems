/* Sorry for being late. */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_interface.h"

void EXTI_voidInit(void)
{
    EXTI_voidSetSenseControl(EXTI_INT0, EXTI_ANY_CHANGE);
    EXTI_voidSetSenseControl(EXTI_INT1, EXTI_ANY_CHANGE);
    EXTI_voidEnable(EXTI_INT0);
    EXTI_voidEnable(EXTI_INT1);
    sei();
}

void EXTI_voidSetSenseControl(u8 Copy_u8Interrupt, u8 Copy_u8Sense)
{
    switch (Copy_u8Interrupt)
    {
        case EXTI_INT0:
            MCUCR = (MCUCR & 0xFCU) | (Copy_u8Sense & 0x03U);
            break;
        case EXTI_INT1:
            MCUCR = (MCUCR & 0xF3U) | ((Copy_u8Sense & 0x03U) << 2);
            break;
        case EXTI_INT2:
            if (Copy_u8Sense == EXTI_FALLING_EDGE) CLR_BIT(MCUCSR, ISC2);
            else if (Copy_u8Sense == EXTI_RISING_EDGE) SET_BIT(MCUCSR, ISC2);
            break;
        default: break;
    }
}

void EXTI_voidEnable(u8 Copy_u8Interrupt)
{
    if (Copy_u8Interrupt <= EXTI_INT2) SET_BIT(GICR, Copy_u8Interrupt);
}

void EXTI_voidDisable(u8 Copy_u8Interrupt)
{
    if (Copy_u8Interrupt <= EXTI_INT2) CLR_BIT(GICR, Copy_u8Interrupt);
}
