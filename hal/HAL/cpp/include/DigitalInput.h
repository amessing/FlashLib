/*
 * DigitalInput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef CPP_HAL_DIGITALINPUT_H_
#define CPP_HAL_DIGITALINPUT_H_

#include <stdint.h>

namespace flashlib {

namespace hal {

class DigitalInput {
	public:
		DigitalInput(uint8_t port);
		~DigitalInput();

		bool get();
	private:
		uint8_t handle;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* DIGITALINPUT_H_ */
