/*
 * pru.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef PRU_PRU_H_
#define PRU_PRU_H_

#include "pru_internal.h"

#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************\
 * PRU initialization
\***********************************************************************/

extern void PRU_initialize(uint32_t* status);
extern void PRU_shutdown(uint32_t* status);

/***********************************************************************\
 * PRU direct port handling
\***********************************************************************/

extern uint8_t PRU_initializePort(uint8_t base, uint8_t port, uint8_t type);
extern void PRU_freePort(uint8_t handle, uint8_t type);

/***********************************************************************\
 * PRU digital
\***********************************************************************/

extern void PRU_digitalWrite(uint8_t handle, uint8_t val);
extern uint8_t PRU_digitalRead(uint8_t handle);

extern void PRU_pulseOut(uint8_t handle, uint32_t us);
extern uint32_t PRU_pulseIn(uint8_t handle);

/***********************************************************************\
 * PRU analog
\***********************************************************************/

extern uint32_t PRU_analogRead(uint8_t handle);

/***********************************************************************\
 * PRU pwm
\***********************************************************************/

extern void PRU_pwmSetDuty(uint8_t handle, uint8_t duty);
extern uint8_t PRU_pwmGetDuty(uint8_t handle);
extern void PRU_pwmSetFrquency(uint8_t handle, uint32_t frequency);
extern uint32_t PRU_pwmGetFrequency(uint8_t handle);


#ifdef __cplusplus
}
#endif

#endif /* PRU_PRU_H_ */
