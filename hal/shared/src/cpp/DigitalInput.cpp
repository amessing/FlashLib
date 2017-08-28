/*
 * DigitalInput.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "cpp/DigitalInput.h"
#include "DIO.h"
#include "cpp/portexception.h"

namespace flashlib {

namespace hal {

DigitalInput::DigitalInput(uint8_t port) {
	if(!HAL_checkDIOPort(port))
		throw port_exception(port, HALPort::DigitalInput);
	handle = HAL_initializeDIOPort(port, GPIO_DIR_INPUT);
}
DigitalInput::~DigitalInput() {
	HAL_freeDIOPort(handle);
}

bool DigitalInput::get(){
	return HAL_getDIO(handle);
}

} /* namespace hal */

} /* namespace flashlib */
