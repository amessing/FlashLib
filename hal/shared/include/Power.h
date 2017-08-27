/*
 * Power.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef HAL_POWER_H_
#define HAL_POWER_H_

#include <stdint.h>

namespace flashlib{

namespace hal{

float HAL_getVinVoltage();
float HAL_getVinCurrent();

} /* namespace hal */

} /* namespace flashlib */

#endif /* POWER_H_ */
