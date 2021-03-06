/*
 * Slave_app.c
 *
 * Created: 2/24/2022 2:43:30 PM
 *  Author: Mahm Oud Sa Ad
 */ 

#include <GPIO.h>
#include <I2C_File.h>
#include <LCD.h>
#include <Slave_app.h>
uint_8 Received_Data =0;

void Slave_Init_system_1()
{
	TWI_1.Micro_state = Slave_Receiver;
	TWI_1.Presaler_Val = No_Presaler;
	
	LCD_Init(); 
	Set_SLA_Value(0b11100000);
	
}
void Slave_Control_system_1()
{
	Received_Data =TWI_Read_Byte_Ack();
	Send_char_LCD(Received_Data);
}

