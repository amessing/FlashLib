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
#include "haltypes.h"

namespace flashlib {

namespace hal {

class port_exception : public std::runtime_error{
	public:
		port_exception(uint8_t port, HALPort type);

		uint8_t port();
		HALPort type();

	private:
		uint8_t eport;
		HALPort etype;
};

} /* namespace hal */

} /* namespace flashlib */

#endif /* INCLUDE_PORTEXCEPTION_H_ */
