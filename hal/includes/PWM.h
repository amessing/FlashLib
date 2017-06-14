/*
 * PWM.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef PWM_H_
#define PWM_H_

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t HAL_initializePWMPort(uint8_t portHandle);
extern void HAL_freePWMPort(uint8_t portHandle);

extern void HAL_setPWMDutyCycle(uint8_t portHandle, float dutyCycle);
extern float HAL_getPWMDutyCycle(uint8_t portHandle);

extern uint32_t HAL_getPWMLoopTime();

#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */
