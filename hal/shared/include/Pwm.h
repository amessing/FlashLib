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

extern bool HAL_checkPWMPort(uint8_t port);
extern uint8_t HAL_initializePWMPort(uint8_t port);
extern void HAL_freePWMPort(uint8_t portHandle);

extern void HAL_setPWMDutyCycle(uint8_t portHandle, float dutyCycle);
extern float HAL_getPWMDutyCycle(uint8_t portHandle);

extern void HAL_setPWMValue(uint8_t portHandle, int value);
extern int HAL_getPWMValue(uint8_t portHandle);

extern void HAL_setPWMFrequency(uint8_t portHandle, float frequency);
extern float HAL_getPWMFrequency(uint8_t portHandle);

extern uint32_t HAL_getPWMLoopTime();

} /* namespace hal */

} /* namespace flashlib */

#endif /* PWM_H_ */