/* Sorry for being late. */

#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_interface.h"

void ADC_voidInit(void)
{
    /* AVCC reference, right-adjusted result, ADC clock = F_CPU/128. */
    ADMUX &= (u8)~((1U << REFS1) | (1U << ADLAR));
    ADMUX |= (1U << REFS0);

    ADCSRA |= (1U << ADPS2) | (1U << ADPS1) | (1U << ADPS0);
    ADCSRA |= (1U << ADEN);
}

u16 ADC_u16Read(u8 Copy_u8Channel)
{
    if (Copy_u8Channel > ADC_CHANNEL_7) return 0;

    ADMUX = (ADMUX & 0xE0U) | (Copy_u8Channel & 0x07U);
    ADCSRA |= (1U << ADSC);

    while (GET_BIT(ADCSRA, ADIF) == 0U) {}
    SET_BIT(ADCSRA, ADIF);

    return ADC;
}
