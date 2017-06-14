/*
 * HAL.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef INCLUDE_HAL_H_
#define INCLUDE_HAL_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void HAL_initialize(uint32_t* status);
extern void HAL_shutdown(uint32_t* status);

extern uint32_t HAL_clockMS();
extern uint32_t HAL_clockUS();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HAL_H_ */
