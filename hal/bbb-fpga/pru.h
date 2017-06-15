/*
 * pru.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef PRU_H_
#define PRU_H_

#include "handles.h"
#include "gpio.h"

//memory
#define SHARED_MEMORY     (0x10000)
#define HANDLE_REGISTER   (0x1)
#define IN_REGISTER       (0x2)
#define OUT_REGISTER      (0x3)
#define TYPE_REGISTER     (0x4)
#define TIME_REGISTER     (0x5)
#define STATUS_REGISTER   (0x10)

//status data
#define STATUS_FINISH     (0x1)
#define STATUS_SUCCESS    (0x1 << 1)
#define STATUS_FAILED     (0x0 << 1)

//handle data - ports
#define HANDLE_PWM        (0x1)
#define HANDLE_ADC        (0x2)
#define HANDLE_DI         (0x3)
#define HANDLE_DO         (0x4)

//handle data - buses
#define HANDLE_SPI        (0x1)

//type data
#define TYPE_INIT         (0x1)
#define TYPE_SHUT         (0x2)
#define TYPE_IN           (0x3)
#define TYPE_OUT          (0x4)
#define TYPE_SETTING	  (0x5)
//type relation
#define TYPE_SYS          (0x1)
#define TYPE_IO           (0x2)
#define TYPE_BUS	      (0x3)

//conversion macros - handle
#define H_BAS(h)          (h & 0xf)
#define H_PIN(h)          ((h >> 4) & 0xf)
#define H_TYP(h)          ((h >> 8) & 0xf)
#define H_HAN(b, p, t)    (b | (p << 4) | (t << 8))

//conversion macros - type
#define T_TAG(t)          (t & 0xf)
#define T_TAK(t)          ((t >> 4) & 0xf)
#define T_SPE(t)		  ((t >> 8) & 0xff)
#define T_TYP(ta, t, s)   (ta | (t << 4) | (s << 8))

/***********************************************************************\
 * PRU utilities
\***********************************************************************/

extern uint32_t PRU_clock();

/***********************************************************************\
 * PRU memory handling
\***********************************************************************/

extern void PRU_MEM_write(uint32_t* memaddr, uint32_t data);
extern void PRU_MEM_read(uint32_t* memaddr, uint32_t* data);
extern void PRU_MEM_clear(uint32_t* memaddr);

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

extern void PRU_initialize();
extern void PRU_shutdown();

extern void PRU_initializePort(uint8_t base, uint8_t pin, uint8_t type);
extern void PRU_initializeBus(uint8_t bus, uint8_t type);

extern void PRU_freePort(uint8_t base, uint8_t pin, uint8_t type);
extern void PRU_freeBus(uint8_t bus, uint8_t type);

extern void PRU_DIO_initialize(uint8_t base, uint8_t pin, uint8_t dir);
extern void PRU_ADC_initialize(uint8_t base, uint8_t pin);
extern void PRU_PWM_initialize(uint8_t base, uint8_t pin);
extern void PRU_SPI_initialize(uint8_t bus);

extern void PRU_DIO_free(uint8_t base, uint8_t pin);
extern void PRU_ADC_free(uint8_t base, uint8_t pin);
extern void PRU_PWM_free(uint8_t base, uint8_t pin);

extern void PRU_SPI_free(uint8_t bus);

/***********************************************************************\
 * PRU settings
\***********************************************************************/

extern void PRU_settingsPort(uint8_t base, uint8_t pin, uint8_t type, uint32_t setting);
extern void PRU_settingsBus(uint8_t bus, uint8_t type, uint32_t setting);

extern void PRU_DIO_settings(uint8_t base, uint8_t pin, uint32_t setting);
extern void PRU_PWM_settings(uint8_t base, uint8_t pin, uint32_t setting);
extern void PRU_ADC_settings(uint8_t base, uint8_t pin, uint32_t setting);

extern void PRU_SPI_settings(uint8_t bus, uint32_t setting);

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

extern uint32_t PRU_getPort(uint8_t base, uint8_t pin, uint8_t type);
extern void PRU_setPort(uint8_t base, uint8_t pin, uint8_t type, uint32_t value);

extern void PRU_inPort(uint8_t base, uint8_t pin, uint8_t type, uint8_t spe_type, uint32_t time);
extern void PRU_outPort(uint8_t base, uint8_t pin, uint8_t type, uint8_t spe_type, uint32_t value, uint32_t time);

/***********************************************************************\
 * PRU handles
\***********************************************************************/

extern void PRU_handle();

extern DIO_handle* PRU_DIO_getHandle(uint8_t handle);
extern ADC_handle* PRU_ADC_getHandle(uint8_t handle);
extern PWM_handle* PRU_PWM_getHandle(uint8_t handle);

extern void PRU_DIO_handle(DIO_handle* handle, uint32_t* time);
extern void PRU_ADC_handle(ADC_handle* handle, uint32_t* time);
extern void PRU_PWM_handle(PWM_handle* handle, uint32_t* time);

/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

extern void PRU_handleHostRequest(uint32_t* status);

#endif /* PRU_H_ */
