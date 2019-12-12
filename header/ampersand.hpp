#ifndef __AMPERSAND_HPP__
#define __AMPERSAND_HPP__

#include "input.hpp"

class Ampersand : public Input {
	public:
		Ampersand(string x) : Input(x) { };
        Ampersand(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;
};

#endif
