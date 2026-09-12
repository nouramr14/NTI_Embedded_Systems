/* Sorry for being late. */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../HAL/KEYPAD/KEYPAD_interface.h"

int main(void)
{
    s32 Local_s32Num1 = 0;
    s32 Local_s32Num2 = 0;
    s32 Local_s32Result = 0;
    u8 Local_u8Calculating = 0;
    u8 Local_u8Error = 0;
    u8 Local_u8Key;
    u8 Local_u8Operator = '\0';

    LCD_voidInit();
    KEYPAD_voidInit();

    while (1)
    {
        Local_u8Key = KEYPAD_u8GetPressedKey();

        if (Local_u8Key != '\0')
        {
            if (Local_u8Key == 'C')
            {
                LCD_voidSendCommand(0x01);
                Local_s32Num1 = 0;
                Local_s32Num2 = 0;
                Local_u8Operator = '\0';
                Local_u8Calculating = 0;
            }
            else if (Local_u8Key >= '0' && Local_u8Key <= '9')
            {
                LCD_voidSendChar(Local_u8Key);
                if (Local_u8Calculating == 0)
                    Local_s32Num1 = (Local_s32Num1 * 10) + (Local_u8Key - '0');
                else
                    Local_s32Num2 = (Local_s32Num2 * 10) + (Local_u8Key - '0');
            }
            else if (Local_u8Key == '+' || Local_u8Key == '-' ||
                     Local_u8Key == '*' || Local_u8Key == '/')
            {
                if (Local_u8Calculating == 0)
                {
                    Local_u8Operator = Local_u8Key;
                    Local_u8Calculating = 1;
                    LCD_voidSendChar(Local_u8Operator);
                }
            }
            else if (Local_u8Key == '=')
            {
                LCD_voidSendChar('=');
                Local_u8Error = 0;

                switch (Local_u8Operator)
                {
                    case '+': Local_s32Result = Local_s32Num1 + Local_s32Num2; break;
                    case '-': Local_s32Result = Local_s32Num1 - Local_s32Num2; break;
                    case '*': Local_s32Result = Local_s32Num1 * Local_s32Num2; break;
                    case '/':
                        if (Local_s32Num2 != 0) Local_s32Result = Local_s32Num1 / Local_s32Num2;
                        else Local_u8Error = 1;
                        break;
                    default: Local_u8Error = 1; break;
                }

                if (Local_u8Error)
                    LCD_voidSendString((const u8 *)"Error");
                else
                    LCD_voidWriteNumber(Local_s32Result);

                if (!Local_u8Error) Local_s32Num1 = Local_s32Result;
                Local_s32Num2 = 0;
                Local_u8Calculating = 0;
                Local_u8Operator = '\0';
            }

            _delay_ms(150);
        }
    }
}
