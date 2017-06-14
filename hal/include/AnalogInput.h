/*
 * AnalogInput.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef ANALOGINPUT_H_
#define ANALOGINPUT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t HAL_initializeAnalogInputPort(uint8_t portHandle);
extern void HAL_freeAnalogInputPort(uint8_t portHandle);

extern float HAL_getAnalogInputVoltage(uint8_t portHandle);
extern uint32_t HAL_getAnalogInputValue(uint8_t portHandle);

extern uint32_t HAL_voltsToValue(uint8_t portHandle, float volts);
extern float HAL_valueToVolts(uint8_t portHandle, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ANALOGINPUT_H_ */
