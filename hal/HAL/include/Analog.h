/*
 * analog.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************\
 * Analog initialization
\***********************************************************************/

extern uint8_t HAL_initializeAnalogInputPort(uint8_t portHandle);
extern void HAL_freeAnalogInputPort(uint8_t portHandle);

extern uint8_t HAL_initializeAnalogOutputPort(uint8_t portHandle);
extern void HAL_freeAnalogOutputPort(uint8_t portHandle);

/***********************************************************************\
 * Analog data io
\***********************************************************************/

extern void HAL_setAnalogOutputValue(uint8_t portHandle, uint32_t value);
extern void HAL_setAnalogOutputVoltage(uint8_t portHandle, float volts);

extern float HAL_getAnalogInputVoltage(uint8_t portHandle);
extern uint32_t HAL_getAnalogInputValue(uint8_t portHandle);

/***********************************************************************\
 * Analog data conversion
\***********************************************************************/

extern uint32_t HAL_voltsToValue(uint8_t portHandle, float volts);
extern float HAL_valueToVolts(uint8_t portHandle, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ANALOG_H_ */
