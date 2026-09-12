/* Sorry for being late. */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/SPI/SPI_interface.h"

int main(void)
{
    SPI_voidInit();
    while (1)
    {
        SPI_u8Transceive('1');
        _delay_ms(1000);
    }
}
