/* Sorry for being late. */

#ifndef TIMER0_CTC_INTERFACE_H
#define TIMER0_CTC_INTERFACE_H

#include "../../LIB/STD_Types.h"

void TIMER0_CTC_voidInit(void);
void TIMER0_CTC_voidSetCompareValue(u8 Copy_u8CompareValue);
void TIMER0_CTC_voidSetCallback(void (*Copy_pvCallback)(void));

#endif
