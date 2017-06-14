/*
 * gpio.h
 *
 *  Created on: Jun 13, 2017
 *      Author: zuk
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "hw/hw_gpio.h"

/***********************************************************************\
 * Macros
\***********************************************************************/

/* GPIO direction setting */
#define GPIO_DIR_INPUT                   (GPIO_OE_OUTPUTEN_DISABLED)
#define GPIO_DIR_OUTPUT                  (GPIO_OE_OUTPUTEN_ENABLED)

/*GPIO value setting*/

#define GPIO_PIN_HIGH                    (0x01)
#define GPIO_PIN_LOW                     (0x00)

/*GPIO interrupt lines*/

#define GPIO_INT_LINE_1                  (0x00)
#define GPIO_INT_LINE_2                  (0x01)

/*GPIO interrupt types*/

#define GPIO_INT_TYPE_NO_LEVEL           (0x01)
#define GPIO_INT_TYPE_LEVEL_LOW          (0x04)
#define GPIO_INT_TYPE_LEVEL_HIGH         (0x08)
#define GPIO_INT_TYPE_BOTH_LEVEL         (0x0C)

#define GPIO_INT_TYPE_NO_EDGE            (0x80)
#define GPIO_INT_TYPE_RISE_EDGE          (0x10)
#define GPIO_INT_TYPE_FALL_EDGE          (0x20)
#define GPIO_INT_TYPE_BOTH_EDGE          (0x30)

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

extern void GPIO_writeDigital(uint8_t base, uint8_t pin, uint8_t value);
extern uint8_t GPIO_readDigital(uint8_t base, uint8_t pin);
extern void GPIO_writeAnalog(uint8_t base, uint8_t pin, uint32_t value);
extern uint32_t GPIO_readAnalog(uint8_t base, uint8_t pin);

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

#endif /* GPIO_H_ */
