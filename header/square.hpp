#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "input.hpp"

class Square : public Input {
	public:
		Square(string x) : Input(x) { };
		int run();
};


#endif
