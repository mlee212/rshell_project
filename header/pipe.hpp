#ifndef __PIPE_HPP__
#define __PIPE_HPP__

#include "input.hpp"

class Pipe : public Input {
	public:
		Pipe(string x) : Input(x) { };
        Pipe(string x, Input * y, Input * z) : Input(x) { left = y; right = z; };
		int run();
        Input * left;
        Input * right;
};

#endif
