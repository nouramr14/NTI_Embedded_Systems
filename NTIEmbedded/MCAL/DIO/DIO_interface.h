/* Sorry for being late. */

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/STD_Types.h"

#define DIO_OUTPUT 1U
#define DIO_INPUT  0U

#define DIO_LOW  0U
#define DIO_HIGH 1U

#define PIN0 0U
#define PIN1 1U
#define PIN2 2U
#define PIN3 3U
#define PIN4 4U
#define PIN5 5U
#define PIN6 6U
#define PIN7 7U

#define PORTA 0U
#define PORTB 1U
#define PORTC 2U
#define PORTD 3U

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8   DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8   DIO_u8ReadPortValue(u8 Copy_u8Port);

#endif
