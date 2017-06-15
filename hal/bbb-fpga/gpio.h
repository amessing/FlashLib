/*
 * gpio.h
 *
 *  Created on: Jun 13, 2017
 *      Author: zuk
 */

#ifndef PRU_GPIO_H_
#define PRU_GPIO_H_

#include <hw/hw_gpio_v2.h>
#include <gpio_v2.h>
#include <hw/hw_types.h>

/***********************************************************************\
 * GPIO base
\***********************************************************************/

extern void GPIO_module_enable(uint8_t base);
extern void GPIO_module_disable(uint8_t base);
extern void GPIO_module_reset(uint8_t base);

/***********************************************************************\
 * GPIO base
\***********************************************************************/

extern void GPIO_dir_set(uint8_t base, uint8_t pin, uint8_t dir);
extern uint8_t GPIO_dir_get(uint8_t base, uint8_t pin);

extern void GPIO_write(uint8_t base, uint8_t pin, uint32_t value);
extern uint32_t GPIO_read(uint8_t base, uint8_t pin);

/***********************************************************************\
 * GPIO Interrupts
\***********************************************************************/

extern void GPIO_interrupt_enable(uint8_t base, uint8_t pin, uint8_t interrput);
extern void GPIO_interrupt_disable(uint8_t base, uint8_t pin, uint8_t interrput);

extern void GPIO_interrupt_trigger(uint8_t base, uint8_t pin, uint8_t interrput);
extern void GPIO_interrupt_clear(uint8_t base, uint8_t pin, uint8_t interrput);
extern void GPIO_interrupt_status(uint8_t base, uint8_t pin, uint8_t interrput, uint8_t* status);

extern uint8_t GPIO_interrupt_getType(uint8_t base, uint8_t pin);
extern void GPIO_interrupt_setType(uint8_t base, uint8_t pin, uint8_t type);

#endif /* PRU_GPIO_H_ */
