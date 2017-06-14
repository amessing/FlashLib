/*
 * fpga.c
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#include "types.h"
#include "gpio.h"
#include "pwm.h"
#include "handles.h"
#include "fpga.h"


void FPGA_initializeModule(uint8_t base){

}
void FPGA_shutdown(){

}

void FPGA_DIO_initializePort(uint8_t base, uint8_t pin){

}
void FPGA_PWM_initializePort(uint8_t base, uint8_t pin){

}
void FPGA_ANA_initializePort(uint8_t base, uint8_t pin){

}

void FPGA_DIO_set(uint8_t base, uint8_t pin, uint8_t value){

}
uint8_t FPGA_DIO_get(uint8_t base, uint8_t pin){
	return 0;
}

void FPGA_PWM_set(uint8_t base, uint8_t pin, uint8_t value){

}
uint8_t FPGA_PWM_get(uint8_t base, uint8_t pin){
	return 0;
}

void FPGA_ANA_set(uint8_t base, uint8_t pin, uint8_t value){

}
uint8_t FPGA_ANA_get(uint8_t base, uint8_t pin){
	return 0;
}


uint8_t FPGA_handleToBase(uint32_t handle){
	return (uint8_t)(handle & 0xff);
}
uint8_t FPGA_handleToPin(uint32_t handle){
	return (uint8_t)((handle >> 8) & 0xff);
}
uint32_t FPGA_pinToHandle(uint8_t base, uint8_t pin){
	return (uint32_t)(base | (pin << 8));
}

void FPGA_setHandlePort(GPIO_handle* gpio_handle, uint32_t handle){
	gpio_handle->base = FPGA_handleToBase(*handle);
	gpio_handle->pin = FPGA_handleToPin(*handle);
}
void FPGA_DIO_setHandleValue(GPIO_handle* gpio_handle, uint32_t value){
	gpio_handle->value = (value & 0xff);
	gpio_handle->time = (uint32_t)((value >> 8) & 0xFFFFFF);
	gpio_handle->type = TYPE_DIO_OUT;
}
void FPGA_PWM_setHandleValue(GPIO_handle* gpio_handle, uint32_t value){
	gpio_handle->value = (value & 0xff);
	gpio_handle->time = (uint32_t)((value >> 8) & 0xFFFFFF);
	gpio_handle->type = TYPE_PWM_OUT;
}
void FPGA_ANA_setHandleValue(GPIO_handle* gpio_handle, uint32_t value){
	gpio_handle->value = (value & 0xff);
	gpio_handle->time = (uint32_t)((value >> 8) & 0xFFFFFF);
	gpio_handle->type = TYPE_ANA_OUT;
}

GPIO_handle* FPGA_handleHostRequest(uint32_t handle, uint32_t* value, uint32_t type, uint32_t* status){
	switch(type){
		case TYPE_SHUTDOWN:
			FPGA_shutdown();
			*status = STATUS_FINISH & STATUS_SUCCESS;
			break;

		case TYPE_PWM_OUT:
			GPIO_handle gpio_handle;
			FPGA_setHandlePort(&gpio_handle, handle);
			FPGA_PWM_setHandleValue(gpio_handle, value);

			*status = STATUS_SUCCESS;
			return &gpio_handle;

		case TYPE_PWM_IN:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			*value = FPGA_PWM_get(base, pin);

			*status = STATUS_SUCCESS;
			break;

		case TYPE_PWM_INIT:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			FPGA_PWM_initializePort(base, pin);

			*status = STATUS_SUCCESS;
			break;

		case TYPE_DIO_OUT:
			GPIO_handle gpio_handle;
			FPGA_setHandlePort(&gpio_handle, handle);
			FPGA_DIO_setHandleValue(gpio_handle, value);

			*status = STATUS_SUCCESS;
			return &gpio_handle;

		case TYPE_DIO_IN:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			*value = FPGA_DIO_get(base, pin);

			*status = STATUS_SUCCESS;
			break;

		case TYPE_DIO_INIT:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			FPGA_DIO_initializePort(base, pin);

			*status = STATUS_SUCCESS;
			break;

		case TYPE_ANA_OUT:
			GPIO_handle gpio_handle;
			FPGA_setHandlePort(&gpio_handle, handle);
			FPGA_ANA_setHandleValue(gpio_handle, value);

			*status = STATUS_SUCCESS;
			return &gpio_handle;

		case TYPE_ANA_IN:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			*value = FPGA_ANA_get(base, pin);

			*status = STATUS_SUCCESS;
			break;

		case TYPE_ANA_INIT:
			uint8_t base = FPGA_handleToBase(handle);
			uint8_t pin = FPGA_handleToPin(handle);
			FPGA_ANA_initializePort(base, pin);

			*status = STATUS_SUCCESS;
			break;
	}

	return NULL;
}
void FPGA_handle(GPIO_handle* handle){
	switch(handle->type){
		case TYPE_ANA_OUT:
			break;
		case TYPE_PWM_OUT:
			break;
		case TYPE_DIO_OUT:
			break;
	}
}


