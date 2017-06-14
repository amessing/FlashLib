/*
 * fpga.h
 *
 *  Created on: Jun 14, 2017
 *      Author: root
 */

#ifndef BEAGLEBONEBLACK_FPGA_FPGA_H_
#define BEAGLEBONEBLACK_FPGA_FPGA_H_

#define HWREG(x) (*((volatile unsigned int *)(x)))

#define SHARED_RAM        (0x10000)
#define HANDLE_REGISTER   (1)
#define VALUE_REGISTER    (2)
#define TYPE_REGISTER     (3)
#define STATUS_REGISTER   (4)

#define STATUS_FINISH     (0x1)
#define STATUS_SUCCESS    (0x1 << 1)
#define STATUS_FAILED     (0x0 << 1)
#define STATUS_WRITE      (0x1 << 2)

#define TYPE_SHUTDOWN     (0x1)
#define TYPE_PWM_OUT      (0x2)
#define TYPE_PWM_IN       (0x3)
#define TYPE_PWM_INIT     (0x4)
#define TYPE_DIO_OUT      (0x5)
#define TYPE_DIO_IN       (0x6)
#define TYPE_DIO_INIT     (0x7)
#define TYPE_ANA_OUT      (0x8)
#define TYPE_ANA_IN       (0x9)
#define TYPE_ANA_INIT     (0x10)


extern void FPGA_initializeModule(uint8_t base);
extern void FPGA_shutdown();

extern void FPGA_DIO_initializePort(uint8_t base, uint8_t pin);
extern void FPGA_PWM_initializePort(uint8_t base, uint8_t pin);
extern void FPGA_ANA_initializePort(uint8_t base, uint8_t pin);

extern void FPGA_DIO_set(uint8_t base, uint8_t pin, uint8_t value);
extern uint8_t FPGA_DIO_get(uint8_t base, uint8_t pin);

extern void FPGA_PWM_set(uint8_t base, uint8_t pin, uint8_t value);
extern uint8_t FPGA_PWM_get(uint8_t base, uint8_t pin);

extern void FPGA_ANA_set(uint8_t base, uint8_t pin, uint8_t value);
extern uint8_t FPGA_ANA_get(uint8_t base, uint8_t pin);

extern uint8_t FPGA_handleToBase(uint32_t handle);
extern uint8_t FPGA_handleToPin(uint32_t handle);
extern uint32_t FPGA_pinToHandle(uint8_t base, uint8_t pin);

extern void FPGA_setHandlePort(GPIO_handle* gpio_handle, uint32_t handle);
extern void FPGA_DIO_setHandleValue(GPIO_handle* gpio_handle, uint32_t value);
extern void FPGA_ANA_setHandleValue(GPIO_handle* gpio_handle, uint32_t value);
extern void FPGA_PWM_setHandleValue(GPIO_handle* gpio_handle, uint32_t value);

extern GPIO_handle* FPGA_handleHostRequest(uint32_t handle, uint32_t* value, uint32_t type, uint32_t* status);
extern void FPGA_handle(GPIO_handle* handle);

#endif /* BEAGLEBONEBLACK_FPGA_FPGA_H_ */
