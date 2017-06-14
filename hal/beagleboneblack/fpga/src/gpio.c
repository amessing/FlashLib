/*
 * gpio.c
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */


#include "gpio.h"
#include "hw_types.h"

/***********************************************************************\
 * GPIO base
\***********************************************************************/

void gpio_module_enable(uint8_t base){
	HWREG(base + GPIO_CTRL) &= ~(GPIO_CTRL_DISABLEMODULE);
}
void gpio_module_disable(uint8_t base){
	HWREG(base + GPIO_CTRL) |= (GPIO_CTRL_DISABLEMODULE);
}
void gpio_module_reset(uint8_t base){
    HWREG(base + GPIO_SYSCONFIG) |= (GPIO_SYSCONFIG_SOFTRESET);

    while(!(HWREG(base + GPIO_SYSSTATUS) & GPIO_SYSSTATUS_RESETDONE));
}

/***********************************************************************\
 * GPIO base
\***********************************************************************/

void gpio_dir_set(uint8_t base, uint8_t pin, uint8_t dir){
	if(dir == GPIO_DIR_OUTPUT)
		HWREG(base + GPIO_OE) &= ~(1 << pin);
	else
		HWREG(base + GPIO_OE) |= (1 << pin);
}
void gpio_dir_get(uint8_t base, uint8_t pin, uint8_t* dir){
	if(!(HWREG(base + GPIO_OE) & (1 << pin)))
		*dir = GPIO_DIR_OUTPUT;
	else
		*dir = GPIO_DIR_INPUT;
}

void gpio_write(uint8_t base, uint8_t pin, uint8_t value){
	if(value == GPIO_PIN_HIGH)
		HWREG(base + GPIO_SETDATAOUT) |= (1 << value);
	else
		HWREG(base + GPIO_CLEARDATAOUT) |= (1 << value);
}
void gpio_read(uint8_t base, uint8_t pin, uint8_t* value){
	*value = (HWREG(base + GPIO_DATAIN) & (1 << pin));
}

/***********************************************************************\
 * GPIO Interrupts
\***********************************************************************/

void gpio_interrupt_enable(uint8_t base, uint8_t pin, uint8_t interrput){
	HWREG(base + GPIO_IRQSTATUS_SET(interrput)) = (1 << pin);
}
void gpio_interrupt_disable(uint8_t base, uint8_t pin, uint8_t interrput){
	HWREG(base + GPIO_IRQSTATUS_CLR(interrput)) = (1 << pin);
}

void gpio_interrupt_trigger(uint8_t base, uint8_t pin, uint8_t interrput){
	HWREG(base + GPIO_IRQSTATUS_RAW(interrput)) = (1 << pin);
}
void gpio_interrupt_clear(uint8_t base, uint8_t pin, uint8_t interrput){
	HWREG(base + GPIO_IRQSTATUS(interrput)) = (1 << pin);
}
void gpio_interrupt_status(uint8_t base, uint8_t pin, uint8_t interrput, uint8_t* status){
	*status = (HWREG(base + GPIO_IRQSTATUS(interrput)) & (1 << pin));
}

void gpio_interrupt_getType(uint8_t base, uint8_t pin, uint8_t* type){
    *type = (GPIO_INT_TYPE_NO_LEVEL | GPIO_INT_TYPE_NO_EDGE);

    /* Checking if logic LOW level trigger interrupt is enabled. */
    if(HWREG(base + GPIO_LEVELDETECT(0)) & (1 << pin)){
        type &= ~(GPIO_INT_TYPE_NO_LEVEL);
        type |= GPIO_INT_TYPE_LEVEL_LOW;
    }
    /* Checking if logic HIGH level trigger interrupt is enabled. */
    if(HWREG(base + GPIO_LEVELDETECT(1)) & (1 << pin)){
        type &= ~(GPIO_INT_TYPE_NO_LEVEL);
        type |= GPIO_INT_TYPE_LEVEL_HIGH;
    }
    /* Checking if rising edge trigger interrupt is enabled. */
    if(HWREG(base + GPIO_RISINGDETECT) & (1 << pin)){
        type &= ~(GPIO_INT_TYPE_NO_EDGE);
        type |= GPIO_INT_TYPE_RISE_EDGE;
    }
    /* Checking if falling edge trigger interrupt is enabled. */
    if(HWREG(base + GPIO_FALLINGDETECT) & (1 << pin)){
        type &= ~(GPIO_INT_TYPE_NO_EDGE);
        type |= GPIO_INT_TYPE_FALL_EDGE;
    }
}
void gpio_interrupt_setType(uint8_t base, uint8_t pin, uint8_t type){
	type &= 0xFF;

    switch(type){
        case GPIO_INT_TYPE_NO_LEVEL:
            HWREG(base + GPIO_LEVELDETECT(0)) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_LEVEL_LOW:
            HWREG(base + GPIO_LEVELDETECT(0)) |= (1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) &= ~(1 << pin);
            HWREG(base + GPIO_RISINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_LEVEL_HIGH:
            HWREG(base + GPIO_LEVELDETECT(0)) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) |= (1 << pin);
            HWREG(base + GPIO_RISINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_BOTH_LEVEL:
            HWREG(base + GPIO_LEVELDETECT(0)) |= (1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) |= (1 << pin);
            HWREG(base + GPIO_RISINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_NO_EDGE:
            HWREG(base + GPIO_RISINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_RISE_EDGE:
            HWREG(base + GPIO_RISINGDETECT) |= (1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(0)) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) &= ~(1 << pin);
        break;
        case GPIO_INT_TYPE_FALL_EDGE:
            HWREG(base + GPIO_RISINGDETECT) &= ~(1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) |= (1 << pin);
            HWREG(base + GPIO_LEVELDETECT(0)) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) &= ~(1 << pin);
        break;

        case GPIO_INT_TYPE_BOTH_EDGE:
            HWREG(base + GPIO_RISINGDETECT) |= (1 << pin);
            HWREG(base + GPIO_FALLINGDETECT) |= (1 << pin);
            HWREG(base + GPIO_LEVELDETECT(0)) &= ~(1 << pin);
            HWREG(base + GPIO_LEVELDETECT(1)) &= ~(1 << pin);
        break;
    }
}
