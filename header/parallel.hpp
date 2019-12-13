#ifndef __PARALLEL_HPP__
#define __PARALLEL_HPP__

#include "input.hpp"

class Parallel : public Input {
	public:
		Parallel(string x) : Input(x) { };
        Parallel(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;

};

#endif
