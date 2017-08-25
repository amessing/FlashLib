/*
 * DigitalInput.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "DigitalInput.h"
#include "include/DIO.h"
#include <stdint.h>

namespace flashlib {

DigitalInput::DigitalInput(uint8_t port) {
	handle = HAL_initializeDIOPort(port, GPIO_DIR_INPUT);
}
DigitalInput::~DigitalInput() {
	HAL_freeDIOPort(handle);
}

uint8_t DigitalInput::get(){
	return HAL_getDIO(handle);
}

} /* namespace flashlib */
