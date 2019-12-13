#ifndef __INPUTREDIRECTION_HPP__
#define __INPUTREDIRECTION_HPP__

#include "input.hpp"

class InputRedirection : public Input {
	public:
		InputRedirection(string x) : Input(x) { };
        InputRedirection(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;
};

#endif
