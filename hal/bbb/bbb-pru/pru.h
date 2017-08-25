/*
 * pru.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef PRU_H_
#define PRU_H_

#include "types.h"
#include "handles.h"
#include "gpio.h"
#include "adc.h"
#include "pwm.h"
#include "defines.h"

#include "hw/hw_pru.h"
#include "hw/hw_types.h"

/***********************************************************************\
 * PRU utilities
\***********************************************************************/

extern uint32_t PRU_clock();
extern void PRU_delay(uint32_t ms);

/***********************************************************************\
 * PRU memory handling
\***********************************************************************/

extern void PRU_MEM_write(uint32_t memoffset, uint32_t data);
extern void PRU_MEM_read(uint32_t memoffset, uint32_t* data);
extern void PRU_MEM_clear(uint32_t memoffset);

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

extern void PRU_initialize(uint32_t* status);
extern void PRU_shutdown(uint32_t* status);

/***********************************************************************\
 * PRU settings
\***********************************************************************/

extern void PRU_settingsPort(uint8_t handle, uint8_t type, uint8_t dir, uint32_t* setting);

extern void PRU_DIO_settings(uint8_t handle, uint8_t dir, uint32_t* setting);
extern void PRU_PWM_settings(uint8_t handle, uint8_t dir, uint32_t* setting);
extern void PRU_ADC_settings(uint8_t handle, uint8_t dir, uint32_t* setting);

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

extern uint32_t PRU_readPort(uint8_t handle, uint8_t type);
extern void PRU_writePort(uint8_t handle, uint8_t type, uint32_t value);

extern uint32_t PRU_DIO_readPort(uint8_t handle);
extern void PRU_DIO_writePort(uint8_t handle, uint32_t value);

extern uint32_t PRU_PWM_readPort(uint8_t handle);
extern void PRU_PWM_writePort(uint8_t handle, uint32_t value);

extern uint32_t PRU_ADC_readPort(uint8_t handle);
extern void PRU_ADC_writePort(uint8_t handle, uint32_t value);

/***********************************************************************\
 * PRU handles
\***********************************************************************/

extern void PRU_handle();
extern void PRU_updateTime();

/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

extern void PRU_handleHostRequest(uint32_t* data_holder, uint32_t* status);

#endif /* PRU_H_ */
