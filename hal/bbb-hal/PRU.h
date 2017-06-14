/*
 * PRU.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef BBBHAL_PRU_H_
#define BBBHAL_PRU_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void PRU_initialize(uint8_t prunum, uint32_t* status);
extern void PRU_shutdown(uint8_t prunum, uint32_t* status);

extern uint32_t* PRU_mapMemory(uint8_t prunum);
extern void PRU_writeMemory(uint32_t* memaddr, uint32_t val);
extern uint32_t* PRU_readMemory(uint32_t* memaddr);

#ifdef __cplusplus
}
#endif

#endif /* BBBHAL_PRU_H_ */
