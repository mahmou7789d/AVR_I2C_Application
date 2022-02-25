/*
 * Master_app.c
 *
 * Created: 2/24/2022 2:42:39 PM
 *  Author: Mahm Oud Sa Ad
 */ 
#include <I2C_File.h>
#include <Master_app.h>
#include <util/delay.h>
uint_8 COUNTER = 0;
void Master_Init_system()
{
	TWI_1.Micro_state = Master_Transmitter;
	TWI_1.Presaler_Val = No_Presaler;
	TWI_1.TWI_state = TWI_Enabled;
	TWI_INIT(50000);
}

void Master_Control_system()
{
	
		_delay_ms(500);
		TWI_Start(0b11100000);
		TWI_Write_Byte(3+48);
		TWI_Stop();
}