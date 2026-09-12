/* Sorry for being late. */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../LIB/STD_Types.h"

void UART_voidInit(void);
void UART_voidSendChar(u8 Copy_u8Data);
u8   UART_u8ReceiveChar(void);

#endif
