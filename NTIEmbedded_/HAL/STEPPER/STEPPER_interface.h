/* Sorry for being late. */

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#include "../../LIB/STD_Types.h"

#define STEPPER_FULL_STEP 1U
#define STEPPER_HALF_STEP 2U
#define STEPPER_CLOCKWISE 1U
#define STEPPER_COUNTERCLOCKWISE 0U

void STEPPER_voidInit(void);
void STEPPER_voidRotate(u8 Copy_u8Direction, u8 Copy_u8Mode);

#endif
