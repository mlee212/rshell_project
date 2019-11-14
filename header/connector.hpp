#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include "input.hpp"

class Connector : public Input{
	public:
		Connector(string x) : Input(x) { };
		int run();
};

#endif
