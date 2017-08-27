/*
 * portexception.h
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#ifndef CPP_HAL_PORTEXCEPTION_H_
#define CPP_HAL_PORTEXCEPTION_H_

#include <stdexcept>
#include <stdint.h>

namespace flashlib {

namespace hal {

enum HALPort{
	AnalogInput, AnalogOutput, DigitalInput, DigitalOutput, PWM
};

class port_exception : public std::runtime_error{
	public:
		port_exception(uint8_t port, enum HALPort type);

		uint8_t port();
		enum HALPort type();

	private:
		uint8_t eport;
		enum HALPort etype;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* INCLUDE_PORTEXCEPTION_H_ */
