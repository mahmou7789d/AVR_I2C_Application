/*
 * Master_app.c
 *
 * Created: 2/24/2022 2:42:39 PM
 *  Author: Mahm Oud Sa Ad
 */ 
#include <GPIO.h>
#include <I2C_File.h>
#include <Master_app.h>
#include <util/delay.h>
#include <LCD.h>
#include <EEPROM.h>
unsigned char counter=0;
void Master_Init_system_1()
{
	
	TWI_1.Presaler_Val=No_Presaler;
	TWI_1.Micro_state = Master_Transmitter;
	TWI_INIT(50000);
}

void Master_Control_system_1()
{
	while(counter<10)
	{
		_delay_ms(500);
		TWI_Start(0b11100000);			// transmit SLA+W
		TWI_Write_Byte(counter+48);		// transmit data
		TWI_Stop();						// transmit stop condition
		counter++;
	}
}

void Master_Init_system_2()
{
	LCD_Init();
	TWI_1.Presaler_Val=No_Presaler;
	TWI_1.Micro_state = Master_Transmitter;
	TWI_INIT(50000);
}

void Master_Control_system_2()
{
	//Write in EEPROM using I2C 
	_delay_ms(500);
	TWI_Start(0b10100000);			// transmit SLA+W
	TWI_Write_Byte(0b00000000);		// transmit data
	TWI_Write_Byte(0x33);
	TWI_Stop();
	
	//Read in EEPROM using I2C
	_delay_ms(200);
	TWI_Start(0b10100000);			// transmit SLA+W
	TWI_Write_Byte(0b00000000);		// transmit data
	TWI_Repeated_Start();
	Write_address_For_Read(0b10100001);
	counter = TWI_Read_Byte_NAck();
	TWI_Stop();
	Send_char_LCD(counter);
	 
}