#ifndef __ARGUMENT_HPP__
#define __ARGUMENT_HPP__

#include "input.hpp"

class Argument : public Input{
	public:
		Argument(string str) { input = str; };
		void run() { };
};

#endif
