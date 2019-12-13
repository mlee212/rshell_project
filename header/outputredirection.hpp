#ifndef __OUTPUTREDIRECTION_HPP__
#define __OUTPUTREDIRECTION_HPP__

#include "input.hpp"

class OutputRedirection : public Input {
	public:
		OutputRedirection(string x) : Input(x) { };
        OutputRedirection(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;
};

#endif
