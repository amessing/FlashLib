/*
 * handles.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef BEAGLEBONEBLACK_FPGA_HANDLES_H_
#define BEAGLEBONEBLACK_FPGA_HANDLES_H_

#define TYPE_ANALOG_OUT  (0x1)
#define TYPE_ANALOG_IN   (0x2)
#define TYPE_DIGITAL_OUT (0x3)
#define TYPE_DIGITAL_IN  (0x4)
#define TYPE_PWM         (0x5)

struct GPIO_handle{
	uint8_t base;
	uint8_t pin;
	uint8_t type;
	uint8_t value;
	uint32_t time;

	GPIO_handle* next;
};

#endif /* BEAGLEBONEBLACK_FPGA_HANDLES_H_ */
