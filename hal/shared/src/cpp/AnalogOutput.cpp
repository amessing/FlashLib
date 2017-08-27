/*
 * AnalogOutput.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#include "AnalogOutput.h"
#include "Analog.h"
#include "portexception.h"

namespace flashlib {

namespace hal {

AnalogOutput::AnalogOutput(uint8_t port){
	if(!HAL_checkAnalogOutputPort(port))
		throw port_exception(port, HALPort::AnalogOutput);
	handle = HAL_initializeAnalogOutputPort(port);
}
AnalogOutput::~AnalogOutput(){
	HAL_freeAnalogOutputPort(handle);
}

void AnalogOutput::setVoltage(float volts){
	HAL_setAnalogOutputVoltage(handle, volts);
}
void AnalogOutput::setValue(int value){
	HAL_setAnalogOutputValue(handle, value);
}

float AnalogOutput::getVoltage(){
	return HAL_getAnalogInputVoltage(handle);
}
int AnalogOutput::getValue(){
	return HAL_getAnalogInputValue(handle);
}

} /* namespace hal */

} /* namespace flashlib */
