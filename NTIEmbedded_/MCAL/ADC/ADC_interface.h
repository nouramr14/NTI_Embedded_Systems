/* Sorry for being late. */

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../LIB/STD_Types.h"

#define ADC_CHANNEL_0 0U
#define ADC_CHANNEL_1 1U
#define ADC_CHANNEL_2 2U
#define ADC_CHANNEL_3 3U
#define ADC_CHANNEL_4 4U
#define ADC_CHANNEL_5 5U
#define ADC_CHANNEL_6 6U
#define ADC_CHANNEL_7 7U

void ADC_voidInit(void);
u16  ADC_u16Read(u8 Copy_u8Channel);

#endif
