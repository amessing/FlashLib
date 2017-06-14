/*
 * hw_pwm.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef HW_PWM_H_
#define HW_PWM_H_

#define PWMSS_CLOCK_CONFIG               (0x08)
#define PWMSS_CLOCK_STATUS               (0x0C)
#define PWMSS_ECAP_CLK_EN_ACK_SHIFT      (0x00)
#define PWMSS_ECAP_CLK_STOP_ACK_SHIFT    (0x01)
#define PWMSS_EHRPWM_CLK_EN_ACK_SHIFT    (0x08)
#define PWMSS_EHRPWM_CLK_STOP_ACK_SHIFT  (0x09)
#define PWMSS_ECAP_CLK_EN_ACK            (0x01)
#define PWMSS_ECAP_CLK_STOP_ACK          (0x02)
#define PWMSS_EHRPWM_CLK_EN_ACK          (0x100)
#define PWMSS_EHRPWM_CLK_STOP_ACK        (0x200)

#endif /* HW_PWM_H_ */
