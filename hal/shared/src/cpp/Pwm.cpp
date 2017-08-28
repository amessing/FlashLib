/*
 * Pwm.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "cpp/Pwm.h"
#include "PWM.h"
#include "cpp/portexception.h"

namespace flashlib {

namespace hal {

Pwm::Pwm(uint8_t port) {
	if(!HAL_checkPWMPort(port))
		throw port_exception(port, HALPort::PWM);
	handle = HAL_initializePWMPort(port);
}
Pwm::~Pwm() {
	HAL_freePWMPort(handle);
}

float Pwm::getDuty(){
	return HAL_getPWMDutyCycle(handle);
}
int Pwm::getValue(){
	return HAL_getPWMValue(handle);
}

void Pwm::setDuty(float duty){
	HAL_setPWMDutyCycle(handle, duty);
}
void Pwm::setValue(int value){
	HAL_setPWMValue(handle, value);
}

} /* namespace hal */

} /* namespace flashlib */
