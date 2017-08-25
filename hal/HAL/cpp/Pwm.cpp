/*
 * Pwm.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "Pwm.h"
#include "include/PWM.h";
#include <stdint.h>

namespace flashlib {

Pwm::Pwm(uint8_t port) {
	handle = HAL_initializePWMPort(port);
}
Pwm::~Pwm() {
	HAL_freePWMPort(handle);
}


} /* namespace flashlib */
