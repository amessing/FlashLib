/*
 * DIO.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef HAL_DIO_H_
#define HAL_DIO_H_

#include <stdint.h>

#define GPIO_DIR_INPUT    (0x1u)
#define GPIO_DIR_OUTPUT   (0x0u)

#define GPIO_PIN_HIGH     (0x1u)
#define GPIO_PIN_LOW      (0x0u)

namespace flashlib{

namespace hal{

/***********************************************************************\
 * DIO initialization
\***********************************************************************/

bool HAL_checkDIOPort(uint8_t port);
uint8_t HAL_initializeDIOPort(uint8_t port, uint8_t dir);
void HAL_freeDIOPort(uint8_t portHandle);

/***********************************************************************\
 * DIO data io
\***********************************************************************/

uint8_t HAL_getDIO(uint8_t portHandle);
void HAL_setDIO(uint8_t portHandle, uint8_t value);
void HAL_pulseOutDIO(uint8_t portHandle, float pulseLength);

} /* namespace hal */

} /* namespace flashlib */

#endif /* DIO_H_ */
