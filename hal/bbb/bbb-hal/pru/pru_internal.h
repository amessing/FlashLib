/*
 * pru_internal.h
 *
 *  Created on: Jun 15, 2017
 *      Author: root
 */

#ifndef PRU_PRU_INTERNAL_H_
#define PRU_PRU_INTERNAL_H_

#include "prussdrv.h"
#include "pruss_intc_mapping.h"

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************\
 * PRU initialization
\***********************************************************************/

extern void PRU_initialize(uint8_t prunum, uint32_t* status);
extern void PRU_shutdown(uint8_t prunum, uint32_t* status);

/***********************************************************************\
 * PRU memory handle
\***********************************************************************/

extern uint32_t* PRU_mapMemory(uint8_t prunum);
extern void PRU_writeMemory(uint32_t* memaddr, uint32_t val);
extern void PRU_readMemory(uint32_t* memaddr, uint32_t* val);

#ifdef __cplusplus
}
#endif

#endif /* PRU_PRU_INTERNAL_H_ */
