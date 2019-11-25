#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "input.hpp"

class Test : public Input {
	public:
		Test(string x) : Input(x) { };
		int run();
};


#endif
