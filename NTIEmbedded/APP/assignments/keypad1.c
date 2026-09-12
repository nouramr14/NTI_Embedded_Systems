/* Sorry for being late. */

#include "../../LIB/STD_Types.h"
#include "../../HAL/KEYPAD/KEYPAD_interface.h"

int main(void)
{
    u8 Local_u8Key;

    KEYPAD_voidInit();

    while (1)
    {
        Local_u8Key = KEYPAD_u8GetPressedKey();
        (void)Local_u8Key;
    }
}
