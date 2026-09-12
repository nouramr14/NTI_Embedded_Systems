/* Sorry for being late. */

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)   ((VAR) |=  (1U << (BIT)))
#define CLR_BIT(VAR,BIT)   ((VAR) &= ~(1U << (BIT)))
#define TOGGLE_BIT(VAR,BIT) ((VAR) ^= (1U << (BIT)))
#define GET_BIT(VAR,BIT)   (((VAR) >> (BIT)) & 0x01U)

#endif
