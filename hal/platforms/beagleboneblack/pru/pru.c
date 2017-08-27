/*
 * pru.c
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#include "pru.h"

volatile uint32_t* shared_memory = 0;
uint8_t pru_status = PRU_IDLE;

/***********************************************************************\
 * PRU utilities
\***********************************************************************/

uint32_t PRU_clock(){
	return 0;
}
void PRU_delay(uint32_t ms){

}

/***********************************************************************\
 * PRU memory handling
\***********************************************************************/

void PRU_MEM_write(uint32_t memoffset, uint32_t data){
	*(shared_memory + memoffset) = data;
}
void PRU_MEM_read(uint32_t memoffset, uint32_t* data){
	*data = *(shared_memory + memoffset);
}
void PRU_MEM_clear(uint32_t memoffset){
	*(shared_memory + memoffset) = 0;
}

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

void PRU_initialize(uint32_t* status){
	//enable access to whole memory map from PRU
	HWREG(PRU_ICSS_CFG + PRU_ICSS_CFG_SYSCFG) &= ~(1 << 4);
	//pointer to shared ram
	shared_memory = (volatile uint32_t *)SHARED_MEMORY;

	//initializing gpio
	GPIO_initialize(shared_memory + GPIO_HANDLE_ADDR);

	*status = PRU_INITIALIZED;
	pru_status = PRU_INITIALIZED;
}
void PRU_shutdown(uint32_t* status){

}

/***********************************************************************\
 * PRU settings
\***********************************************************************/

void PRU_settingsPort(uint8_t handle, uint8_t type, uint8_t dir, uint32_t* setting){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_settings(handle, dir, setting);
			break;
		case HANDLE_DIO:
			PRU_DIO_settings(handle, dir, setting);
			break;
		case HANDLE_ADC:
			PRU_ADC_settings(handle, dir, setting);
			break;
	}
}

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

uint32_t PRU_readPort(uint8_t handle, uint8_t type){
	return 0;
}
void PRU_writePort(uint8_t handle, uint8_t type, uint32_t value){

}

/***********************************************************************\
 * PRU handles
\***********************************************************************/

void PRU_handle(){

}
void PRU_updateTime(){
	uint32_t time = PRU_clock();
	PRU_MEM_write(shared_memory, time);
}

/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

void PRU_handleHostRequest(uint32_t* data_holder, uint32_t* status){
	PRU_MEM_read(TYPE_REGISTER, data_holder);

	//getting the type of task to execute
	uint8_t t_type = T_TAG(*data_holder);
	uint8_t e_type = T_TAK(*data_holder);

	if(t_type == TYPE_SYS){//pru general tasks
		switch(e_type){
			case TYPE_INIT:
				*status = PRU_INITIALIZED;
				break;
			case TYPE_SHUT:
				*status = PRU_SHUTDOWN;
				break;
		}
	}else if(t_type == TYPE_IO){//io related tasks
		PRU_MEM_read(HANDLE_REGISTER, data_holder);

		uint8_t handle = H_BAS(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		switch(e_type){
			case TYPE_IN:
				*data_holder = PRU_readPort(handle, h_type);
				PRU_MEM_write(OUT_REGISTER, *data_holder);
				break;
			case TYPE_OUT:
				PRU_MEM_read(IN_REGISTER, data_holder);
				PRU_writePort(handle, h_type, *data_holder);
				break;
			case TYPE_SETTING_SET:
				PRU_MEM_read(IN_REGISTER, data_holder);
				PRU_settingsPort(handle, h_type, 1, data_holder);
				break;
			case TYPE_SETTING_GET:
				PRU_MEM_read(IN_REGISTER, data_holder);
				PRU_settingsPort(handle, h_type, 0, data_holder);
				PRU_MEM_write(OUT_REGISTER, *data_holder);
				break;
		}
	}else if(t_type == TYPE_BUS){//bus related tasks

	}else if(t_type == TYPE_DEV){// device related tasks

	}

	PRU_MEM_clear(TYPE_REGISTER);
	PRU_MEM_clear(HANDLE_REGISTER);
	PRU_MEM_clear(IN_REGISTER);

	*data_holder = 0;
}



