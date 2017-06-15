/*
 * handles.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef PRU_HANDLES_H_
#define PRU_HANDLES_H_

struct DIO_handle{
	uint8_t base;
	uint8_t pin;
	uint8_t type;
	uint8_t value;

	uint32_t time;
};

struct PWM_handle{
	uint8_t base;
	uint8_t pin;
	uint8_t type;
	uint8_t value;
	uint8_t end_value;

	uint32_t time;
};

struct ADC_handle{

};

#endif /* PRU_HANDLES_H_ */
