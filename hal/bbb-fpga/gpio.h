/*
 * gpio.h
 *
 *  Created on: Jun 13, 2017
 *      Author: zuk
 */

#ifndef PRU_GPIO_H_
#define PRU_GPIO_H_

#include "hw/hw_gpio.h"
#include "hw/hw_types.h"

#define GPIO_DIR_INPUT    (0x1u)
#define GPIO_DIR_OUTPUT   (0x0u)

#define GPIO_PIN_HIGH     (0x1u)
#define GPIO_PIN_LOW      (0x0u)

#define DIO_BASE(x)       (x & 0xf)
#define DIO_PIN(x)        ((x >> 4) & 0xf)
#define DIO_HANDLE(b, p)  (b | (p << 4))

/***********************************************************************\
 * GPIO base
\***********************************************************************/

extern void GPIO_initialize(uint32_t* handle_addr);
extern void GPIO_shutdown();

extern void GPIO_module_enable(uint8_t base);
extern void GPIO_module_disable(uint8_t base);
extern void GPIO_module_reset(uint8_t base);

/***********************************************************************\
 * GPIO io
\***********************************************************************/

extern void GPIO_dir_set(uint8_t base, uint8_t pin, uint8_t dir);
extern uint8_t GPIO_dir_get(uint8_t base, uint8_t pin);

extern void GPIO_write(uint8_t base, uint8_t pin, uint32_t value);
extern uint32_t GPIO_read(uint8_t base, uint8_t pin);

/***********************************************************************\
 * DIO handles
\***********************************************************************/

extern uint8_t DIO_handle_init(uint8_t base, uint8_t pin, uint8_t dir);
extern void DIO_handle_dispose(uint8_t handle);

extern DIO_handle* DIO_handle_get(uint8_t handle);

/***********************************************************************\
 * GPIO conversion
\***********************************************************************/

uint32_t GPIO_base_get(uint8_t base){
	switch(base){
		case 0: return GPIO0;
		case 1: return GPIO1;
		case 2: return GPIO2;
		case 3: return GPIO3;
	}
	return 0;
}

#endif /* PRU_GPIO_H_ */
