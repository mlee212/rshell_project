#ifndef __ARGUMENT_HPP__
#define __ARGUMENT_HPP__

#include "input.hpp"

class Argument : public Input {
	public:
		Argument(string);
		void run();
}

#endif
