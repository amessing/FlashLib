/*
 * HAL.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef HAL_H_
#define HAL_H_

extern void HAL_initialize(uint32_t* status);
extern void HAL_shutdown(uint32_t* status);

extern uint32_t HAL_clockMS();
extern uint32_t HAL_clockUS();

#endif /* INCLUDE_HAL_H_ */
