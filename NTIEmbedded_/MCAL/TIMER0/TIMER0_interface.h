/* Sorry for being late. */

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../LIB/STD_Types.h"

void TIMER0_voidInitNormal(void);
void TIMER0_voidSetPreload(u8 Copy_u8Preload);
void TIMER0_voidSetCallback(void (*Copy_pvCallback)(void));

#endif
