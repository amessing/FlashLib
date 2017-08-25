/*
 * DigitalOutput.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

namespace flashlib {

class DigitalOutput {
	public:
		DigitalOutput(uint8_t port);
		~DigitalOutput();

		void pulse(float ms);
		void set(int value);
		void high();
		void low();

		int get();
	private:
		uint8_t handle;
};

} /* namespace flashlib */

#endif /* DIGITALOUTPUT_H_ */
