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

#define SHARED_MEMORY     (0x10000)
#define HANDLE_REGISTER   (0x1)
#define VALUE_REGISTER    (0x2)
#define TYPE_REGISTER     (0x3)
#define STATUS_REGISTER   (0x4)

#define STATUS_FINISH     (0x1)
#define STATUS_SUCCESS    (0x1 << 1)
#define STATUS_FAILED     (0x0 << 1)
#define STATUS_WRITE      (0x1 << 2)

//E
#define TYPE_CLOSE         (0x0)
#define TYPE_INIT          (0x1)
#define TYPE_HAN           (0x2)
//S (<< 2)
#define TYPE_SYSTEM        (0x0)
#define TYPE_IO            (0x1)
//D (<< 3)
#define TYPE_IN            (0x0)
#define TYPE_OUT           (0x1)
//T (<< 4)
#define TYPE_ANALOG        (0x0)
#define TYPE_DIGITAL       (0x1)
#define TYPE_PWM           (0x2)
//M
#define PWM_PROGOUT        (0x1) // << 6
#define PWM_SETTING        (0x2) // << 6

#define DIO_PULSEIN        (0x1) // << 6

#define T_SET_ALL(e, s, d, t)          (e | (s << 2) | (d << 3) | (t << 4))

#define T_EXEC_GET(t)                  (t & 1)
#define T_SYS_GET(t)                   ((t >> 2) & 1)
#define T_DIR_GET(t)                   ((t >> 3) & 1)
#define T_IO_GET(t)                    ((t >> 4) & 3)
#define T_EXTRA_GET(t)                 ((t >> 6) & 3)

#define T_EXEC_SET(t, v)               (t | v)
#define T_SYS_SET(t, v)                (t | (v << 2))
#define T_DIR_SET(t, v)                (t | (v << 3))
#define T_IO_SET(t, v)                 (t | (v << 4))
#define T_EXTRA_SET(t, v)              (t | (v << 6))


#define H_BASE(h)                      (h & 0xf)
#define H_PIN(h)                       ((h >> 4) & 0xf)
#define H_HANDLE(b, p)                 (b | (p << 4))

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
extern void PRU_freePort(uint8_t base, uint8_t pin, uint8_t type);

extern void PRU_GPIO_initialize(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t d_type);
extern void PRU_PWM_initialize(uint8_t base, uint8_t pin, uint8_t d_type);

extern void PRU_GPIO_free(uint8_t base, uint8_t pin, uint8_t t_type);
extern void PRU_PWM_free(uint8_t base, uint8_t pin);

/***********************************************************************\
 * PRU input-output
\***********************************************************************/

extern uint8_t PRU_get(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t m_type);
extern void PRU_set(uint8_t base, uint8_t pin, uint8_t t_type, uint8_t m_type);

/***********************************************************************\
 * PRU handles
\***********************************************************************/

extern void PRU_handle();

extern GPIO_handle* PRU_GPIO_getHandle(uint8_t handle);
extern PWM_handle* PRU_PWM_getHandle(uint8_t handle);

extern void PRU_GPIO_handle(GPIO_handle* handle, uint32_t time);
extern void PRU_PWM_handle(PWM_handle* handle, uint32_t time);

/***********************************************************************\
 * PRU user interaction
\***********************************************************************/

extern void PRU_handleHostRequest(uint32_t* status);

#endif /* PRU_H_ */
