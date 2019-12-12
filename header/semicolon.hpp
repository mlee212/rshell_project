#ifndef __SEMICOLON_HPP__
#define __SEMICOLON_HPP__

#include "input.hpp"

class Semicolon : public Input {
	public:
		Semicolon(string x) : Input(x) { };
        Semicolon(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;

};

#endif
