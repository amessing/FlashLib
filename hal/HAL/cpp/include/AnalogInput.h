/*
 * AnalogInput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef CPP_HAL_ANALOGINPUT_H_
#define CPP_HAL_ANALOGINPUT_H_

#include <stdint.h>

namespace flashlib {

namespace hal {

class AnalogInput {
	public:
		AnalogInput(uint8_t port);
		~AnalogInput();

		float getVoltage();
		int getValue();
	private:
		uint8_t handle;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* ANALOGINPUT_H_ */
