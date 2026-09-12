/* Sorry for being late. */

#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"

#define LCD_DATA_PORT PORTA
#define LCD_CTRL_PORT PORTB
#define LCD_RS_PIN    PIN0
#define LCD_RW_PIN    PIN1
#define LCD_EN_PIN    PIN2

void LCD_voidInit(void)
{
    DIO_voidSetPortDirection(LCD_DATA_PORT, 0xFF);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);

    _delay_ms(40);
    LCD_voidSendCommand(0x38);
    _delay_us(40);
    LCD_voidSendCommand(0x0C);
    _delay_us(40);
    LCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Data)
{
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Data);

    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);
}

void LCD_voidSendString(const u8 *Copy_pu8String)
{
    if (Copy_pu8String == 0) return;
    while (*Copy_pu8String != '\0')
    {
        LCD_voidSendChar(*Copy_pu8String);
        Copy_pu8String++;
    }
}

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Local_u8Address = (Copy_u8Y == 0U) ? Copy_u8X : (u8)(Copy_u8X + 0x40U);
    LCD_voidSendCommand((u8)(0x80U | Local_u8Address));
}

void LCD_voidWriteNumber(s32 Copy_s32Number)
{
    u8 Local_au8Digits[11];
    u8 Local_u8Index = 0;

    if (Copy_s32Number == 0)
    {
        LCD_voidSendChar('0');
        return;
    }

    if (Copy_s32Number < 0)
    {
        LCD_voidSendChar('-');
        Copy_s32Number = -Copy_s32Number;
    }

    while (Copy_s32Number > 0)
    {
        Local_au8Digits[Local_u8Index++] = (u8)((Copy_s32Number % 10) + '0');
        Copy_s32Number /= 10;
    }

    while (Local_u8Index > 0)
        LCD_voidSendChar(Local_au8Digits[--Local_u8Index]);
}
