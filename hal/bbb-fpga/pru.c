/*
 * pru.c
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#include "pru.h"

uint32_t last_time;
uint32_t* data_holder = 0;

/***********************************************************************\
 * PRU utilities
\***********************************************************************/

uint32_t PRU_clock(){
	return 0;
}

/***********************************************************************\
 * PRU memory handling
\***********************************************************************/

void PRU_MEM_write(uint32_t* memaddr, uint32_t data){

}
void PRU_MEM_read(uint32_t* memaddr, uint32_t* data){

}
void PRU_MEM_clear(uint32_t* memaddr){

}

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

void PRU_initialize(){
	//enable access to whole memory map from PRU
	HWREG(PRU_ICSS_CFG + PRU_ICSS_CFG_SYSCFG) &= ~(1 << 4);
	//pointer to shared ram
	shared_memory = (volatile uint32_t *)SHARED_MEMORY;

	//initializing gpio
	GPIO_initialize(shared_memory + GPIO_HANDLE_ADDR);
}
void PRU_shutdown(){

}

uint8_t PRU_initializePort(uint8_t handle, uint8_t type){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_initialize(&handle);
			break;
		case HANDLE_DI:
			PRU_DIO_initialize(&handle, GPIO_DIR_INPUT);
			break;
		case HANDLE_DO:
			PRU_DIO_initialize(&handle, GPIO_DIR_OUTPUT);
			break;
		case HANDLE_ADC:
			PRU_ADC_initialize(&handle);
			break;
	}
	return H_HAN(handle, 0);
}
uint8_t PRU_initializeBus(uint8_t bus, uint8_t type){
	switch(type){
		case HANDLE_SPI:
			PRU_SPI_initialize(&bus);
			break;
	}
	return bus;
}
uint8_t PRU_initializeDev(uint8_t handle, uint8_t type){
	switch(type){
		case HANDLE_COUNTER:
			PRU_COUNTER_initialize(&handle);
			break;
	}
	return 0; //TODO: implement
}

void PRU_freePort(uint8_t handle, uint8_t type){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_free(handle);
			break;
		case HANDLE_DI:
		case HANDLE_DO:
			PRU_DIO_free(handle);
			break;
		case HANDLE_ADC:
			PRU_ADC_free(handle);
			break;
	}
}
void PRU_freeBus(uint8_t bus, uint8_t type){
	switch(type){
		case HANDLE_SPI:
			PRU_SPI_free(bus);
			break;
	}
}
void PRU_freeDev(uint8_t handle, uint8_t type){
	switch(type){
		case HANDLE_COUNTER:
			PRU_COUNTER_free(handle);
			break;
	}
}

/***********************************************************************\
 * PRU settings
\***********************************************************************/

void PRU_settingsPort(uint8_t handle, uint8_t type, uint8_t dir, uint32_t* setting){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_settings(handle, dir, setting);
			break;
		case HANDLE_DI:
		case HANDLE_DO:
			PRU_DIO_settings(handle, dir, setting);
			break;
		case HANDLE_ADC:
			PRU_ADC_settings(handle, dir, setting);
			break;
	}
}
void PRU_settingsBus(uint8_t bus, uint8_t type, uint8_t dir, uint32_t* setting){
	switch(type){
		case HANDLE_SPI:
			PRU_SPI_settings(bus, dir, setting);
			break;
	}
}
void PRU_settingsDev(uint8_t handle, uint8_t type, uint8_t dir, uint32_t* setting){
	switch(type){
		case HANDLE_COUNTER:
			PRU_COUNTER_settings(handle, dir, setting);
			break;
	}
}

/***********************************************************************\
 * PRU input-output
\***********************************************************************/


/***********************************************************************\
 * PRU handles
\***********************************************************************/


/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

void PRU_handleHostRequest(uint32_t* status){
	PRU_MEM_read(shared_memory + TYPE_REGISTER, data_holder);

	//getting the type of task to execute
	uint8_t t_type = T_TAG(*data_holder);
	uint8_t e_type = T_TAK(*data_holder);
	uint8_t s_type = T_SPE(*data_holder);

	if(t_type == TYPE_SYS){//pru general tasks

	}else if(t_type == TYPE_IO){//io related tasks
		PRU_MEM_read(shared_memory + HANDLE_REGISTER, data_holder);

		uint8_t handle = H_BAS(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		PRU_MEM_read(shared_memory + TIME_REGISTER, data_holder);
		uint32_t time = *data_holder;

		switch(e_type){
			case TYPE_INIT:
				*data_holder = PRU_initializePort(handle, h_type);
				PRU_MEM_write(shared_memory + OUT_REGISTER, *data_holder);
				break;
			case TYPE_SHUT:
				PRU_freePort(handle, h_type);
				break;
			case TYPE_IN:
				PRU_inPort(handle, h_type, s_type, time);
				break;
			case TYPE_OUT:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_outPort(handle, h_type, s_type, value, time);
				break;
			case TYPE_SETTING_SET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsPort(handle, h_type, 1, &value);
				break;
			case TYPE_SETTING_GET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsPort(handle, h_type, 0, &value);
				PRU_MEM_write(shared_memory + OUT_REGISTER, value);
				break;
		}
	}else if(t_type == TYPE_BUS){//bus related tasks
		PRU_MEM_read(shared_memory + HANDLE_REGISTER, data_holder);

		uint8_t bus = H_BAS(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		switch(e_type){
			case TYPE_INIT:
				*data_holder = PRU_initializeBus(bus, h_type);
				PRU_MEM_write(shared_memory + OUT_REGISTER, *data_holder);
				break;
			case TYPE_SHUT:
				PRU_freeBus(bus, h_type);
				break;
			case TYPE_SETTING_SET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsBus(bus, h_type, 1, &value);
				break;
			case TYPE_SETTING_GET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsBus(bus, h_type, 0, &value);
				PRU_MEM_write(shared_memory + OUT_REGISTER, value);
				break;
		}
	}else if(t_type == TYPE_DEV){// device related tasks
		PRU_MEM_read(shared_memory + HANDLE_REGISTER, data_holder);

		uint8_t handle = H_BAS(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		switch(e_type){
			case TYPE_INIT:
				*data_holder = PRU_initializeDev(handle, h_type);
				PRU_MEM_write(shared_memory + OUT_REGISTER, *data_holder);
				break;
			case TYPE_SHUT:
				PRU_freeDev(handle, h_type);
				break;
			case TYPE_SETTING_SET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsDev(handle, h_type, 1, &value);
				break;
			case TYPE_SETTING_GET:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsDev(handle, h_type, 0, &value);
				PRU_MEM_write(shared_memory + OUT_REGISTER, value);
				break;
		}
	}

	PRU_MEM_clear(shared_memory + TYPE_REGISTER);
	PRU_MEM_clear(shared_memory + HANDLE_REGISTER);
	PRU_MEM_clear(shared_memory + IN_REGISTER);
	PRU_MEM_clear(shared_memory + TIME_REGISTER);

	*data_holder = 0;
}



