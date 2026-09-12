/* Sorry for being late. */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "../../LIB/STD_Types.h"

void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendChar(u8 Copy_u8Data);
void LCD_voidSendString(const u8 *Copy_pu8String);
void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidWriteNumber(s32 Copy_s32Number);

#endif
