/*
 * pru_internal.c
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */


#include "pru_internal.h"
#include "defines.h"

#ifdef __cplusplus
"C" {
#endif

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

pru_data_t* pru_initialize(uint8_t prunum, char* programfile, uint32_t* status){
	pru_data_t pru_data;
	pru_data.prunum = prunum;

	tpruss_intc_initdata pru_initdata = PRUSS_INTC_INITDATA;
	prussdrv_init();
	prussdrv_open(PRU_EVTOUT_0 + prunum * 3);
	prussdrv_pruintc_init(&pru_initdata);

	prussdrv_exec_program(prunum, programfile);

	pru_mapMemory(pru_data);

	return &pru_data;
}
void pru_shutdown(pru_data_t* pru_data, uint32_t* status){
	*(pru_data->shared_memory + TYPE_REGISTER) = T_TYP(TYPE_SYS, TYPE_SHUT);
	pru_sendInterrupt(pru_data->prunum);
	pru_waitInterrupt(pru_data->prunum);

	prussdrv_pru_disable(pru_data->prunum);
	prussdrv_exit();
}

/***********************************************************************\
 * PRU memory handle
\***********************************************************************/

void pru_mapMemory(pru_data_t* pru_data){
	void* p;
	prussdrv_map_prumem(PRUSS0_SHARED_DATARAM, &p);
	pru_data->shared_memory = (unsigned int*)p;
}

/***********************************************************************\
 * PRU interrupts
\***********************************************************************/

void pru_waitInterrupt(uint8_t prunum){
	prussdrv_pru_wait_event(PRU_EVTOUT_0 + prunum * 3);
	prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT + prunum);
}
void pru_sendInterrupt(uint8_t prunum){
	prussdrv_pru_send_event(ARM_PRU0_INTERRUPT + prunum);
}

/***********************************************************************\
 * PRU IO
\***********************************************************************/

void pru_io_write(pru_data_t* pru_data, uint8_t handle, uint8_t type, uint32_t data){
	*(pru_data->shared_memory + TYPE_REGISTER) = T_TYP(TYPE_IO, TYPE_OUT);
	*(pru_data->shared_memory + HANDLE_REGISTER) = H_HAN(handle, type);
	*(pru_data->shared_memory + IN_REGISTER) = data;

	pru_sendInterrupt(pru_data->prunum);
	pru_waitInterrupt(pru_data->prunum);
}
uint32_t pru_io_read(pru_data_t* pru_data, uint8_t handle, uint8_t type){
	*(pru_data->shared_memory + TYPE_REGISTER) = T_TYP(TYPE_IO, TYPE_IN);
	*(pru_data->shared_memory + HANDLE_REGISTER) = H_HAN(handle, type);

	pru_sendInterrupt(pru_data->prunum);
	pru_waitInterrupt(pru_data->prunum);

	return *(pru_data->shared_memory + OUT_REGISTER);
}

void pru_io_settings_write(pru_data_t* pru_data, uint8_t handle, uint8_t type, uint16_t setting, int16_t value){
	*(pru_data->shared_memory + TYPE_REGISTER) = T_TYP(TYPE_IO, TYPE_SETTING_SET);
	*(pru_data->shared_memory + HANDLE_REGISTER) = H_HAN(handle, type);
	*(pru_data->shared_memory + IN_REGISTER) = S_DATA(setting, value);

	pru_sendInterrupt(pru_data->prunum);
	pru_waitInterrupt(pru_data->prunum);
}
int16_t pru_io_settings_read(pru_data_t* pru_data, uint8_t handle, uint8_t type, uint16_t setting){
	*(pru_data->shared_memory + TYPE_REGISTER) = T_TYP(TYPE_IO, TYPE_SETTING_GET);
	*(pru_data->shared_memory + HANDLE_REGISTER) = H_HAN(handle, type);
	*(pru_data->shared_memory + IN_REGISTER) = setting;

	pru_sendInterrupt(pru_data->prunum);
	pru_waitInterrupt(pru_data->prunum);

	return *(pru_data->shared_memory + OUT_REGISTER);
}

#ifdef __cplusplus
}
#endif
