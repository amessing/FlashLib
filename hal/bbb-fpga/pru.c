/*
 * pru.c
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#include "pru.h"


DIO_handle* first_dio_handle = 0;
PWM_handle* first_pwm_handle = 0;
ADC_handle* first_adc_handle = 0;

uint32_t last_time;

uint32_t* shared_memory = SHARED_MEMORY;
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

}
void PRU_shutdown(){

}

void PRU_initializePort(uint8_t base, uint8_t pin, uint8_t type){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_initialize(base, pin);
			break;
		case HANDLE_DI:
			PRU_DIO_initialize(base, pin, GPIO_DIR_INPUT);
			break;
		case HANDLE_DO:
			PRU_DIO_initialize(base, pin, GPIO_DIR_OUTPUT);
			break;
		case HANDLE_ADC:
			PRU_ADC_initialize(base, pin);
			break;
	}
}
void PRU_initializeBus(uint8_t bus, uint8_t type){
	switch(type){
		case HANDLE_SPI:
			PRU_SPI_initialize(bus);
			break;
	}
}


void PRU_DIO_initialize(uint8_t base, uint8_t pin, uint8_t dir){

}
void PRU_ADC_initialize(uint8_t base, uint8_t pin){

}
void PRU_PWM_initialize(uint8_t base, uint8_t pin){

}

void PRU_SPI_initialize(uint8_t bus){

}


void PRU_freePort(uint8_t base, uint8_t pin, uint8_t type){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_free(base, pin);
			break;
		case HANDLE_DI:
		case HANDLE_DO:
			PRU_DIO_free(base, pin);
			break;
		case HANDLE_ADC:
			PRU_ADC_free(base, pin);
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

void PRU_DIO_free(uint8_t base, uint8_t pin){

}
void PRU_ADC_free(uint8_t base, uint8_t pin){

}
void PRU_PWM_free(uint8_t base, uint8_t pin){

}

void PRU_SPI_free(uint8_t bus){

}

/***********************************************************************\
 * PRU settings
\***********************************************************************/

void PRU_settingsPort(uint8_t base, uint8_t pin, uint8_t type, uint32_t setting){
	switch(type){
		case HANDLE_PWM:
			PRU_PWM_settings(base, pin);
			break;
		case HANDLE_DI:
		case HANDLE_DO:
			PRU_DIO_settings(base, pin);
			break;
		case HANDLE_ADC:
			PRU_ADC_settings(base, pin);
			break;
	}
}
void PRU_settingsBus(uint8_t bus, uint8_t type, uint32_t setting){
	switch(type){
		case HANDLE_SPI:
			PRU_SPI_settings(bus);
			break;
	}
}

void PRU_DIO_settings(uint8_t base, uint8_t pin, uint32_t setting){

}
void PRU_PWM_settings(uint8_t base, uint8_t pin, uint32_t setting){

}
void PRU_ADC_settings(uint8_t base, uint8_t pin, uint32_t setting){

}

void PRU_SPI_settings(uint8_t bus, uint32_t setting){

}

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

uint32_t PRU_getPort(uint8_t base, uint8_t pin, uint8_t type){
	return 0;
}
void PRU_setPort(uint8_t base, uint8_t pin, uint8_t type, uint32_t value){

}

void PRU_inPort(uint8_t base, uint8_t pin, uint8_t type, uint8_t spe_type, uint32_t time){

}
void PRU_outPort(uint8_t base, uint8_t pin, uint8_t type, uint8_t spe_type, uint32_t value, uint32_t time){

}

/***********************************************************************\
 * PRU handles
\***********************************************************************/

void PRU_handle(){

}

DIO_handle* PRU_DIO_getHandle(uint8_t handle){
	return 0;
}
ADC_handle* PRU_ADC_getHandle(uint8_t handle){
	return 0;
}
PWM_handle* PRU_PWM_getHandle(uint8_t handle){
	return 0;
}

void PRU_DIO_handle(DIO_handle* handle, uint32_t* time){

}
void PRU_ADC_handle(ADC_handle* handle, uint32_t* time){

}
void PRU_PWM_handle(PWM_handle* handle, uint32_t* time){

}

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

		uint8_t base = H_BAS(*data_holder);
		uint8_t pin = H_PIN(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		PRU_MEM_read(shared_memory + TIME_REGISTER, data_holder);
		uint32_t time = *data_holder;

		switch(e_type){
			case TYPE_INIT:
				PRU_initializePort(base, pin, h_type);
				break;
			case TYPE_SHUT:
				PRU_freePort(base, pin, h_type);
				break;
			case TYPE_IN:
				PRU_inPort(base, pin, h_type, s_type, time);
				break;
			case TYPE_OUT:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_outPort(base, pin, h_type, s_type, value, time);
				break;
			case TYPE_SETTING:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsPort(base, pin, h_type, value);
				break;
		}
	}else if(t_type == TYPE_BUS){//bus related tasks
		PRU_MEM_read(shared_memory + HANDLE_REGISTER, data_holder);

		uint8_t bus = H_BAS(*data_holder);
		uint8_t h_type = H_TYP(*data_holder);

		switch(e_type){
			case TYPE_INIT:
				PRU_initializeBus(bus, h_type);
				break;
			case TYPE_SHUT:
				PRU_freeBus(bus, h_type);
				break;
			case TYPE_SETTING:
				PRU_MEM_read(shared_memory + IN_REGISTER, data_holder);
				uint32_t value = *data_holder;
				PRU_settingsBus(bus, h_type, value);
				break;
		}
	}

	PRU_MEM_clear(shared_memory + TYPE_REGISTER);
	PRU_MEM_clear(shared_memory + HANDLE_REGISTER);
	PRU_MEM_clear(shared_memory + IN_REGISTER);
	PRU_MEM_clear(shared_memory + TIME_REGISTER);

	*data_holder = 0;
}



