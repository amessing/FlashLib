/*
 * AnalogInput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef ANALOGINPUT_H_
#define ANALOGINPUT_H_

namespace flashlib {

class AnalogInput {
	public:
		AnalogInput(uint8_t port);
		~AnalogInput();

		float getVoltage();
		int getValue();
	private:
		uint8_t handle;
};

} /* namespace flashlib */

#endif /* ANALOGINPUT_H_ */
