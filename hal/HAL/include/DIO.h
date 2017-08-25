/*
 * DIO.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef DIO_H_
#define DIO_H_

#define GPIO_DIR_INPUT    (0x1u)
#define GPIO_DIR_OUTPUT   (0x0u)

#define GPIO_PIN_HIGH     (0x1u)
#define GPIO_PIN_LOW      (0x0u)


/***********************************************************************\
 * DIO initialization
\***********************************************************************/

extern uint8_t HAL_initializeDIOPort(uint8_t portHandle, uint8_t dir);
extern void HAL_freeDIOPort(uint8_t portHandle);

/***********************************************************************\
 * DIO data io
\***********************************************************************/

extern uint8_t HAL_getDIO(uint8_t portHandle);

extern void HAL_setDIO(uint8_t portHandle, uint8_t value);
extern void HAL_pulseOutDIO(uint8_t portHandle, float ms);


#endif /* DIO_H_ */