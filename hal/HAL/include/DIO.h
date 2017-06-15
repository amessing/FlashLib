/*
 * DIO.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef DIO_H_
#define DIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************\
 * DIO initialization
\***********************************************************************/

extern uint8_t HAL_initializeDIOPort(uint8_t portHandle, uint8_t dir);
extern void HAL_freeDIOPort(uint8_t portHandle);

/***********************************************************************\
 * DIO data io
\***********************************************************************/

extern uint8_t HAL_getDIO(uint8_t portHandle);
extern float HAL_pulseInDIO(uint8_t portHandle);

extern void HAL_setDIO(uint8_t portHandle, uint8_t value);
extern void HAL_pulseOutDIO(uint8_t portHandle, float ms);

#ifdef __cplusplus
}
#endif

#endif /* DIO_H_ */
