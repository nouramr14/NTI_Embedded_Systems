/* Sorry for being late. */

#define F_CPU 8000000UL
#include "../../HAL/STEPPER/STEPPER_interface.h"

int main(void)
{
    STEPPER_voidInit();
    while (1)
        STEPPER_voidRotate(STEPPER_CLOCKWISE, STEPPER_FULL_STEP);
}
