/*
 * pru.c
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */


#include "types.h"
#include "gpio.h"
#include "pwm.h"
#include "handles.h"
#include "fpga.h"

#define SICR_REGISTER    (0x20024)
#define INTERRUPT_CLEAR  (21)

void PRU_clearRegisterValue(uint32_t* memaddr);
void PRU_setRegisterValue(uint32_t* memaddr, uint32_t* value);
void PRU_getRegisterValue(uint32_t* memaddr, uint32_t* value);

void PRU_addHandle(GPIO_handle* handle);
void PRU_removeHandle(GPIO_handle* handle, GPIO_handle* pre_handle);

uint32_t PRU_clock();

volatile register uint32_t __R31;

uint32_t* shared_ram = (uint32_t*)SHARED_RAM;

uint32_t* handle_reg = 0;
uint32_t* type_reg = 0;
uint32_t* value_reg = 0;

uint8_t finish = 0;
uint32_t status = 0;
uint32_t pre_time = 0;
uint32_t time = 0;

GPIO_handle* first_handle = NULL;
GPIO_handle* new_handle = NULL;
GPIO_handle* current_handle = NULL;
GPIO_handle* temp_current = NULL;

int main(void){

	pre_time = PRU_clock();
	while(finish == 0){

		if(__R31 & (1 << 30)){//check for host interrupt
			//get register values
			PRU_getRegisterValue(shared_ram + HANDLE_REGISTER, handle_reg);
			PRU_getRegisterValue(shared_ram + VALUE_REGISTER, value_reg);
			PRU_getRegisterValue(shared_ram + TYPE_REGISTER, type_reg);

			//handle host request
			new_handle = FPGA_handleHostRequest(*handle_reg, value_reg, *type_reg, &status);

			//update request status to the host
			PRU_setRegisterValue(shared_ram + STATUS_REGISTER, &status);

			//if host request included getting data, set the data to the register
			if((status & STATUS_WRITE))
				PRU_setRegisterValue(shared_ram + VALUE_REGISTER, value_reg);
			else //otherwise clear register
				PRU_clearRegisterValue(shared_ram + VALUE_REGISTER);

			//clear used registers
			PRU_clearRegisterValue(shared_ram + HANDLE_REGISTER);
			PRU_clearRegisterValue(shared_ram + TYPE_REGISTER);

			//clear interrupt
			PRU_setRegisterValue(SICR_REGISTER, &INTERRUPT_CLEAR);


			//if finish was requested than report finish
			if((status & STATUS_FINISH)){
				finish = 1;
				break;
			}

			//if new gpio handle was added, add it to linked list
			if(new_handle != NULL)
				PRU_addHandle(new_handle);

			//interrupt host that task was completed
			__R31 = 35;
		}

		time = PRU_clock() - pre_time;

		//iterate over the handles linked list and handle them
		current_handle = first_handle;
		temp_current = NULL;
		while(current_handle != NULL){
			current_handle->time -= time;
			if(time <= 0)
				PRU_removeHandle(current_handle, temp_current);
			else
				FPGA_handle(current_handle);

			temp_current = current_handle;
			current_handle = current_handle->next;
		}
		pre_time = PRU_clock();
	}

	//clear all handles
	current_handle = first_handle;
	temp_current = NULL;
	while(current_handle != NULL){
		temp_current = current_handle;
		current_handle = current_handle->next;
		free(temp_current);
	}

	//interrupt host for shutdown
	__R31 = 35;
	//halt pru program
	__halt();
	return 0;
}

void PRU_addHandle(GPIO_handle* handle){
	GPIO_handle* temp = first_handle;
	first_handle = handle;
	handle->next = temp;
}
void PRU_removeHandle(GPIO_handle* handle, GPIO_handle* pre_handle){
	pre_handle->next = handle->next;
	clear(handle);
	handle = pre_handle;
}

void PRU_clearRegisterValue(uint32_t* memaddr){
	HWREG(memaddr) = 0;
}
void PRU_setRegisterValue(uint32_t* memaddr, uint32_t* value){
	HWREG(memaddr) = &value;
}
void PRU_getRegisterValue(uint32_t* memaddr, uint32_t* value){
	*value = HWREG(memaddr);
}

uint32_t PRU_clock(){
	return 0;//IMPLEMENT
}
