/* Sorry for being late. */

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../LIB/STD_Types.h"

#define SPI_MASTER 0U
#define SPI_SLAVE  1U

#ifndef SPI_MODE
#define SPI_MODE SPI_MASTER
#endif

void SPI_voidInit(void);
void SPI_voidSendChar(u8 Copy_u8Data);
u8   SPI_u8GetChar(void);
u8   SPI_u8Transceive(u8 Copy_u8Data);

#endif
