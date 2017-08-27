/*
 * Pwm.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef CPP_HAL_PWM_H_
#define CPP_HAL_PWM_H_

#include <stdint.h>

namespace flashlib {

namespace hal {

class Pwm {
	public:
		Pwm(uint8_t port);
		~Pwm();

		float getDuty();
		int getValue();

		void setDuty(float duty);
		void setValue(int value);
	private:
		uint8_t handle;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* PWM_H_ */
