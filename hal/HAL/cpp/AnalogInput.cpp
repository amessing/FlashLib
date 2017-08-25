/*
 * AnalogInput.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "AnalogInput.h"
#include "include/Analog.h"
#include <stdint.h>

namespace flashlib {

AnalogInput::AnalogInput(uint8_t port) {
	handle = HAL_initializeAnalogInputPort(port);
}
AnalogInput::~AnalogInput() {
	HAL_freeAnalogInputPort(handle);
}

int AnalogInput::getValue(){
	return HAL_getAnalogInputValue(handle);
}
float AnalogInput::getVoltage(){
	return HAL_getAnalogInputVoltage(handle);
}

} /* namespace flashlib */
