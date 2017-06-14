/*
 * Power.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef POWER_H_
#define POWER_H_

#ifdef __cplusplus
extern "C" {
#endif

float HAL_getVinVoltage();
float HAL_getVinCurrent();

#ifdef __cplusplus
}
#endif

#endif /* POWER_H_ */
