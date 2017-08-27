/*
 * Counter.h
 *
 *  Created on: Jun 16, 2017
 *      Author: root
 */

#ifndef HAL_COUNTER_H_
#define HAL_COUNTER_H_

#include <stdint.h>

namespace flashlib{

namespace hal{

/***********************************************************************\
 * Counter initialization
\***********************************************************************/

extern uint8_t HAL_initializeCounter();
extern void HAL_freeCounter(uint8_t handle);

/***********************************************************************\
 * Counter settings
\***********************************************************************/

extern void HAL_setCounterMode(uint8_t mode);
extern uint8_t HAL_getCounterMode();

} /* namespace hal */

} /* namespace flashlib */

#endif /* INCLUDE_COUNTER_H_ */
