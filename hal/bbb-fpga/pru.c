/*
 * pru.c
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#include "pru.h"


GPIO_handle* first_gpio_handle;
PWM_handle* first_pwm_handle;

uint32_t last_time;

uint32_t* shared_memory = SHARED_MEMORY;

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
	HWREG(memaddr) = data;
}
void PRU_MEM_read(uint32_t* memaddr, uint32_t* data){
	*data = HWREG(memaddr);
}
void PRU_MEM_clear(uint32_t* memaddr){
	HWREG(memaddr) = 0;
}

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

void PRU_initialize(){

}
void PRU_shutdown(){

}

void PRU_initializePort(uint8_t base, uint8_t pin, uint8_t type){
	uint8_t t_type = T_IO_GET(type);
	uint8_t d_type = T_DIR_GET(type);

	switch(t_type){
		case TYPE_ANALOG:
		case TYPE_DIGITAL:
			PRU_GPIO_initialize(base, pin, t_type, d_type);
			break;
		case TYPE_PWM:
			PRU_PWM_initialize(base, pin, d_type);
			break;
	}
}
void PRU_freePort(uint8_t base, uint8_t pin, uint8_t type){
	uint8_t t_type = T_IO_GET(type);

	switch(t_type){
		case TYPE_ANALOG:
		case TYPE_DIGITAL:
			PRU_GPIO_free(base, pin, t_type);
			break;
		case TYPE_PWM:
			PRU_PWM_free(base, pin);
			break;
	}
}

void PRU_GPIO_initialize(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t d_type){

}
void PRU_PWM_initialize(uint8_t base, uint8_t pin){

}

void PRU_GPIO_free(uint8_t base, uint8_t pin, uint8_t t_type){

}
void PRU_PWM_free(uint8_t base, uint8_t pin){

}

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

uint8_t PRU_get(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t m_type){
	return 0;
}
void PRU_set(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t m_type){

}

/***********************************************************************\
 * PRU handles
\***********************************************************************/

void PRU_handle(){
	uint32_t clock_time = PRU_clock();
	uint32_t time = clock_time - last_time;

	//iterate over handles

	last_time = clock_time;
}

GPIO_handle* PRU_GPIO_getHandle(uint8_t handle){
	return first_gpio_handle + handle;
}
PWM_handle* PRU_PWM_getHandle(uint8_t handle){
	return first_pwm_handle + handle;
}

void PRU_GPIO_handle(GPIO_handle* handle, uint32_t time){
	switch(TIO(handle->type)){
		case TYPE_ANALOG:
			handle->time -= time;
			if(handle->time <= 0){
				GPIO_writeAnalog(handle->base, handle->pin, GPIO_PIN_LOW);
				free(handle);
			}
			break;
		case TYPE_DIGITAL:
			if(TDIR(handle->type) == TYPE_OUT){
				handle->time -= time;
				if(handle->time <= 0){
					GPIO_writeDigital(handle->base, handle->pin, GPIO_PIN_LOW);
					free(handle);
				}
			}else{
				handle->time += time;
				uint8_t val = GPIO_readDigital(handle->base, handle->pin);
				if(val != handle->value){
					//send pulse in value
				}
			}
			break;
	}
}
void PRU_PWM_handle(PWM_handle* handle, uint32_t time){
	uint8_t pwm_type = T_PWM_PROGOUT_GET(handle->type);
	if(pwm_type == PWM_PROGOUT){
		handle->value += 1;
		if(handle->value > handle->end_value)
			handle->type = T_PWM_PROGOUT_SET(handle->type, 0);
	}
	handle->time -= time;
	if(handle->time <= 0){
		//stop pwm
		free(handle);
	}
}

/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

void PRU_handleHostRequest(uint32_t* status){
	uint32_t* data_holder;
	PRU_MEM_read(shared_memory + TYPE_REGISTER, data_holder);

	uint8_t type = (uint8_t)data_holder;
	uint8_t e_type = T_EXEC_GET(type);
	uint8_t t_type = T_IO_GET(type);
	uint8_t d_type = T_DIR_GET(type);
	uint8_t m_type = T_EXTRA_GET(type);

	if(T_SYS_GET(type) == TYPE_SYSTEM){
		if(T_EXEC_GET(type) == TYPE_INIT){
			PRU_initialize();
		}else{
			PRU_shutdown();
			*status = STATUS_FINISH;
		}
	}else{
		PRU_MEM_read(shared_memory + HANDLE_REGISTER, data_holder);
		uint8_t base = H_BASE(*data_holder);
		uint8_t pin = H_PIN(*data_holder);


		if(e_type == TYPE_INIT)
			PRU_initializePort(base, pin, type);

		else if(e_type == TYPE_CLOSE)
			PRU_freePort(base, pin, type);

		else{
			uint8_t value = 0;

			if(d_type == TYPE_IN){
				value = PRU_get(base, pin, t_type, m_type);
				if(m_type != DIO_PULSEIN)
					PRU_MEM_write(shared_memory + VALUE_REGISTER, value);
			}else{
				PRU_MEM_read(shared_memory + VALUE_REGISTER, data_holder);
				value = (uint8_t)*data_holder;
				PRU_set(base, pin, t_type, m_type);
			}
		}
	}
}






