/*
 * HAL.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef HAL_HAL_H_
#define HAL_HAL_H_

#include <stdint.h>

namespace flashlib{

namespace hal{

extern void HAL_initialize(int* status);
extern void HAL_shutdown(int* status);

extern uint32_t HAL_clockMS();

extern char* HAL_boardName();

} /* namespace hal */

} /* namespace flashlib */

#endif /* INCLUDE_HAL_H_ */
