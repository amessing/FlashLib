/*
 * Counter.h
 *
 *  Created on: Jun 16, 2017
 *      Author: root
 */

#ifndef COUNTER_H_
#define COUNTER_H_

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


#endif /* INCLUDE_COUNTER_H_ */
