/*
 * AnalogOutput.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef ANALOGOUTPUT_H_
#define ANALOGOUTPUT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t HAL_initializeAnalogOutputPort(uint8_t portHandle);
extern void HAL_freeAnalogOutputPort(uint8_t portHandle);

extern void HAL_setAnalogOutputValue(uint8_t portHandle, uint32_t value);
extern uint32_t HAL_getAnalogOutputValue(uint8_t portHandle);

extern void HAL_setAnalogOutputVoltage(uint8_t portHandle, float volts);
extern float HAL_getAnalogOutputVoltage(uint8_t portHandle);

#ifdef __cplusplus
}
#endif

#endif /* ANALOGOUTPUT_H_ */
