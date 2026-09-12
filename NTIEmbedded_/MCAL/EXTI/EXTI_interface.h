/* Sorry for being late. */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../LIB/STD_Types.h"

#define EXTI_INT0 0U
#define EXTI_INT1 1U
#define EXTI_INT2 2U

#define EXTI_LOW_LEVEL      0U
#define EXTI_ANY_CHANGE     1U
#define EXTI_FALLING_EDGE   2U
#define EXTI_RISING_EDGE    3U

void EXTI_voidInit(void);
void EXTI_voidSetSenseControl(u8 Copy_u8Interrupt, u8 Copy_u8Sense);
void EXTI_voidEnable(u8 Copy_u8Interrupt);
void EXTI_voidDisable(u8 Copy_u8Interrupt);

#endif
