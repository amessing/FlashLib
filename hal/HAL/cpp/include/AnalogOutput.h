/*
 * AnalogOutput.h
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#ifndef CPP_HAL_ANALOGOUTPUT_H_
#define CPP_HAL_ANALOGOUTPUT_H_

#include <stdint.h>

namespace flashlib {

namespace hal {

class AnalogOutput {
	public:
		AnalogOutput(uint8_t port);
		~AnalogOutput();

		void setVoltage(float volts);
		void setValue(int value);

		float getVoltage();
		int getValue();
	private:
		uint8_t handle;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* CPP_ANALOGOUTPUT_H_ */
