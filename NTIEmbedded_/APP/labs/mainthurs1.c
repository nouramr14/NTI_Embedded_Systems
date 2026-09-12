/* Sorry for being late. */

#define F_CPU 8000000UL
#include "../../LIB/STD_Types.h"
#include "../../HAL/LCD/LCD_interface.h"

int main(void)
{
    LCD_voidInit();
    LCD_voidSendString((const u8 *)"Salma");
    while (1) {}
}
