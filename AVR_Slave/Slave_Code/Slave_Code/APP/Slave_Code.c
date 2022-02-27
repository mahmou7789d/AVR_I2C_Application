/*
 * Slave_Code.c
 *
 * Created: 2/24/2022 2:34:52 PM
 *  Author: Mahm Oud Sa Ad
 */ 

#include <Slave_app.h>


int main(void)
{
	Slave_Init_system_1();
    while(1)
    {
		Slave_Control_system_1();
    }
}