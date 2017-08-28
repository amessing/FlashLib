/*
 * DigitalOutput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef CPP_HAL_DIGITALOUTPUT_H_
#define CPP_HAL_DIGITALOUTPUT_H_

#include <stdint.h>

namespace flashlib {

namespace hal {

class DigitalOutput {
	public:
		DigitalOutput(uint8_t port);
		~DigitalOutput();

		void pulse(float ms);
		void set(int value);
		void high();
		void low();

		bool get();
	private:
		uint8_t handle;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* DIGITALOUTPUT_H_ */
