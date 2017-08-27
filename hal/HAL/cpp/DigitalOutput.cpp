/*
 * DigitalOutput.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "DigitalOutput.h"
#include "DIO.h"
#include "portexception.h"

namespace flashlib {

namespace hal {

DigitalOutput::DigitalOutput(uint8_t port) {
	if(!HAL_checkDIOPort(port))
		throw port_exception(port, HALPort::DigitalOutput);
	handle = HAL_initializeDIOPort(port, GPIO_DIR_OUTPUT);
}
DigitalOutput::~DigitalOutput() {
	HAL_freeDIOPort(handle);
}

void DigitalOutput::pulse(float ms){
	HAL_pulseOutDIO(handle, ms);
}
void DigitalOutput::set(int value){
	HAL_setDIO(handle, value);
}
void DigitalOutput::high(){
	HAL_setDIO(handle, GPIO_PIN_HIGH);
}
void DigitalOutput::low(){
	HAL_setDIO(handle, GPIO_PIN_LOW);
}

bool DigitalOutput::get(){
	return HAL_getDIO(handle);
}

} /* namespace hal */

} /* namespace flashlib */
