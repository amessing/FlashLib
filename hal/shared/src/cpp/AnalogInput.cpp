/*
 * AnalogInput.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "AnalogInput.h"
#include "Analog.h"
#include "portexception.h"

namespace flashlib {

namespace hal {

AnalogInput::AnalogInput(uint8_t port) {
	if(!HAL_checkAnalogInputPort(port))
		throw port_exception(port, HALPort::AnalogInput);
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

} /* namespace hal */

} /* namespace flashlib */
