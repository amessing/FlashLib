/*
 * portexception.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#include "portexception.h"
#include <string>

namespace flashlib {

namespace hal {

port_exception::port_exception(uint8_t port, enum HALPort type)
			: runtime_error("Port " + std::to_string(port) + " is not a valid port of type: " +
					std::to_string(static_cast<int>(type))){
	this->eport = port;
	this->etype = type;
}

uint8_t port_exception::port(){
	return this->eport;
}
enum HALPort port_exception::type(){
	return this->etype;
}

} /* namespace hal */

} /* namespace flashlib */
