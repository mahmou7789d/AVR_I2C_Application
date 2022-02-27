/*
 * Master_app.h
 *
 * Created: 2/24/2022 2:43:06 PM
 *  Author: Mahm Oud Sa Ad
 */ 


#ifndef MASTER_APP_H_
#define MASTER_APP_H_

void Master_Init_system_1();

void Master_Control_system_1();



//********************************************************* Interfacing EEPROM With AVR *******************
/*
	You will usually need an external EEPROM when your system has a certain set of user configurable settings that you need to save even when the system is powered off;
	so that the system starts with these configurations the next time it is powered on.
	In this case, using an external EEPROM gives you the advantage of having a larger storage space (than the internal EEPROM inbuilt in Atmega32)
	in addition to keeping the user configurations safe from being lost even if the MCU fails.
*/
void Master_Init_system_2();

void Master_Control_system_2();
#endif /* MASTER_APP_H_ */