/*
 * FPGA.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef BBBHAL_FPGA_H_
#define BBBHAL_FPGA_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void FPGA_initialize(uint32_t* status);
extern void FPGA_shutdown(uint32_t* status);

extern uint8_t FPGA_getPortHandle(uint8_t base, uint8_t port);
extern void FPGA_freePort(uint8_t handle);
extern void FPGA_writeHandle(uint8_t handle, uint32_t val);
extern uint32_t FPGA_readHandle(uint8_t handle);

extern uint32_t* FPGA_handleToRegister(uint8_t handle);
extern uint8_t FPGA_registerToHandle(uint32_t* handle);

extern void FPGA_digitalWrite(uint8_t handle, uint8_t val);
extern uint8_t FPGA_digitalRead(uint8_t handle);
extern void FPGA_pulseOut(uint8_t handle, uint32_t ns);
extern uint32_t FPGA_pulseIn(uint8_t handle);

extern void FPGA_analogWrite(uint8_t handle, uint32_t val);
extern uint32_t FPGA_analogRead(uint8_t handle);

extern void FPGA_pwmSetDuty(uint8_t handle, uint8_t duty);
extern uint8_t FPGA_pwmGetDuty(uint8_t handle);
extern void FPGA_pwmSetFrquency(uint8_t handle, uint32_t frequency);
extern uint32_t FPGA_pwmGetFrequency(uint8_t handle);

extern uint32_t FPGA_readClock();

#ifdef __cplusplus
}
#endif

#endif /* BBBHAL_FPGA_H_ */
