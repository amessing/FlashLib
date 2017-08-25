/*
 * pru.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef PRU_PRU_H_
#define PRU_PRU_H_

#define HANDLE_PWM        (0x1)
#define HANDLE_ADC        (0x2)
#define HANDLE_DI         (0x3)
#define HANDLE_DO         (0x4)

//handle data - buses
#define HANDLE_SPI        (0x1)

//handle data - devices
#define HANDLE_COUNTER    (0x1)

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

extern void PRU_initialize(uint32_t* status);
extern void PRU_shutdown(uint32_t* status);

extern void PRU_disableIO();
extern void PRU_enableIO();

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

extern void PRU_pulseOut(uint8_t handle, uint32_t length);
extern uint32_t PRU_pulseIn(uint8_t handle);

/***********************************************************************\
 * PRU analog
\***********************************************************************/

extern uint16_t PRU_analogRead(uint8_t handle);

/***********************************************************************\
 * PRU pwm
\***********************************************************************/

extern void PRU_pwmSetDuty(uint8_t handle, uint8_t duty);
extern uint8_t PRU_pwmGetDuty(uint8_t handle);

extern void PRU_pwmSetFrquency(uint8_t handle, uint32_t frequency);
extern uint32_t PRU_pwmGetFrequency(uint8_t handle);

#endif /* PRU_PRU_H_ */
