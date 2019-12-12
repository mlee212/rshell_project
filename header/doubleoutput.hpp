#ifndef __DOUBLEOUTPUT_HPP__
#define __DOUBLEOUTPUT_HPP__

#include "input.hpp"

class DoubleOutput : public Input {
	public:
		DoubleOutput(string x) : Input(x) { };
        DoubleOutput(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;
};

#endif
