/*
 * DigitalInput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

namespace flashlib {

class DigitalInput {
	public:
		DigitalInput(uint8_t port);
		~DigitalInput();

		uint8_t get();
	private:
		uint8_t handle;
};

} /* namespace flashlib */

#endif /* DIGITALINPUT_H_ */
