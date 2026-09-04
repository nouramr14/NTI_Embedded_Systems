/*
 * main.c
 *
 *  Created on: Aug 31, 2026
 *      Author: DELL
 */
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include"LIB/BIT_MATH.h"
#include"LIB/STD_Types.h"
#include<util/delay.h>




int main()
{
	LCD_vidInit();


		 LCD_vidDisplayString((u8*)"Nour");
		 _delay_ms(1000);

}
