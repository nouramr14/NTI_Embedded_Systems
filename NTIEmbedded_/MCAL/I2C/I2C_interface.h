/* Sorry for being late. */

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../LIB/STD_Types.h"

void I2C_voidInit(void);
void I2C_voidStart(void);
void I2C_voidStop(void);
void I2C_voidWrite(u8 Copy_u8Data);
u8   I2C_u8ReadAck(void);
u8   I2C_u8ReadNack(void);

#endif
