/*
 * handles.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef PRU_HANDLES_H_
#define PRU_HANDLES_H_

#include "types.h"

struct DIO_handle{
	uint8_t base;
	uint8_t pin;
	uint8_t dir;
	uint8_t value;
};

struct PWM_handle{
	uint8_t base;
	uint8_t pin;
	uint8_t type;
	uint8_t value;
	uint8_t end_value;
};

struct ADC_handle{
	uint32_t value;
	uint32_t value_buffer[8];
};

#endif /* PRU_HANDLES_H_ */
