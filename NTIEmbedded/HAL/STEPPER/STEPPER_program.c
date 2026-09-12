/* Sorry for being late. */

#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "STEPPER_interface.h"

static const u8 g_STEPPER_FullStep[4] = {0x01, 0x02, 0x04, 0x08};
static const u8 g_STEPPER_HalfStep[8] = {0x09, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08};

void STEPPER_voidInit(void)
{
    DIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN2, DIO_OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN3, DIO_OUTPUT);
    DIO_voidSetPortValue(PORTC, 0x00);
}

void STEPPER_voidRotate(u8 Copy_u8Direction, u8 Copy_u8Mode)
{
    const u8 *Local_pu8Sequence;
    u8 Local_u8Length;

    if (Copy_u8Mode == STEPPER_FULL_STEP)
    {
        Local_pu8Sequence = g_STEPPER_FullStep;
        Local_u8Length = 4;
    }
    else if (Copy_u8Mode == STEPPER_HALF_STEP)
    {
        Local_pu8Sequence = g_STEPPER_HalfStep;
        Local_u8Length = 8;
    }
    else return;

    for (u8 Local_u8Step = 0; Local_u8Step < Local_u8Length; Local_u8Step++)
    {
        u8 Local_u8Index = (Copy_u8Direction == STEPPER_CLOCKWISE)
                          ? Local_u8Step
                          : (u8)(Local_u8Length - 1U - Local_u8Step);
        DIO_voidSetPortValue(PORTC, Local_pu8Sequence[Local_u8Index]);
        _delay_ms(10);
    }
}
