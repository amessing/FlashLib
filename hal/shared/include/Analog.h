/*
 * analog.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef HAL_ANALOG_H_
#define HAL_ANALOG_H_

#include <stdint.h>

namespace flashlib{

namespace hal{

/***********************************************************************\
 * Analog initialization
\***********************************************************************/

bool HAL_checkAnalogInputPort(uint8_t port);
uint8_t HAL_initializeAnalogInputPort(uint8_t port);
void HAL_freeAnalogInputPort(uint8_t portHandle);

bool HAL_checkAnalogOutputPort(uint8_t port);
uint8_t HAL_initializeAnalogOutputPort(uint8_t port);
void HAL_freeAnalogOutputPort(uint8_t portHandle);

/***********************************************************************\
 * Analog data io
\***********************************************************************/

void HAL_setAnalogOutputValue(uint8_t portHandle, uint32_t value);
void HAL_setAnalogOutputVoltage(uint8_t portHandle, float volts);

float HAL_getAnalogInputVoltage(uint8_t portHandle);
uint32_t HAL_getAnalogInputValue(uint8_t portHandle);

/***********************************************************************\
 * Analog data conversion
\***********************************************************************/

uint32_t HAL_voltsToValue(uint8_t portHandle, float volts);
float HAL_valueToVolts(uint8_t portHandle, uint32_t value);

} /* namespace hal */

} /* namespace flashlib */

#endif /* ANALOG_H_ */
