#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "input.hpp"

class TestCommand : public Input {
	public:
		TestCommand(string x) : Input(x) { };
		int run();
};


#endif
