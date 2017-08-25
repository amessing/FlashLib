/*
 * Pwm.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef PWM_H_
#define PWM_H_

namespace flashlib {

class Pwm {
	public:
		Pwm(uint8_t port);
		~Pwm();
	private:
		uint8_t handle;
};

} /* namespace flashlib */

#endif /* PWM_H_ */
