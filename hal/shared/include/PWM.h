/*
 * PWM.h
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#ifndef HAL_PWM_H_
#define HAL_PWM_H_

#include <stdint.h>

namespace flashlib{

namespace hal{

bool HAL_checkPWMPort(uint8_t port);
uint8_t HAL_initializePWMPort(uint8_t port);
void HAL_freePWMPort(uint8_t portHandle);

void HAL_setPWMDutyCycle(uint8_t portHandle, float dutyCycle);
float HAL_getPWMDutyCycle(uint8_t portHandle);

void HAL_setPWMValue(uint8_t portHandle, int value);
int HAL_getPWMValue(uint8_t portHandle);

void HAL_setPWMFrequency(uint8_t portHandle, float frequency);
float HAL_getPWMFrequency(uint8_t portHandle);

uint32_t HAL_getPWMLoopTime();

} /* namespace hal */

} /* namespace flashlib */

#endif /* PWM_H_ */
