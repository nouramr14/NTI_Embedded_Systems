/* Sorry for being late. */

#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYPAD_interface.h"

static const u8 g_KEYPAD_au8Map[4][4] =
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

void KEYPAD_voidInit(void)
{
    DIO_voidSetPortDirection(PORTC, 0x0F);
    DIO_voidSetPortValue(PORTC, 0xFF); /* input pull-ups + inactive columns */
}

u8 KEYPAD_u8GetPressedKey(void)
{
    static const u8 Local_au8ColumnPins[4] = {PIN4, PIN5, PIN6, PIN7};

    for (u8 Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
    {
        DIO_voidSetPinValue(PORTC, PIN4, DIO_HIGH);
        DIO_voidSetPinValue(PORTC, PIN5, DIO_HIGH);
        DIO_voidSetPinValue(PORTC, PIN6, DIO_HIGH);
        DIO_voidSetPinValue(PORTC, PIN7, DIO_HIGH);
        DIO_voidSetPinValue(PORTC, Local_au8ColumnPins[Local_u8Col], DIO_LOW);

        _delay_ms(2);

        for (u8 Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
        {
            if (DIO_u8ReadPinValue(PORTC, Local_u8Row) == DIO_LOW)
            {
                _delay_ms(20);
                while (DIO_u8ReadPinValue(PORTC, Local_u8Row) == DIO_LOW) {}
                return g_KEYPAD_au8Map[Local_u8Row][Local_u8Col];
            }
        }
    }

    return '\0';
}
