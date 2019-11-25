#define __PARALLEL_HPP__
#ifndef __PARALLEL_HPP__
#include "input.hpp"

class Parallel : public Input {
    public:
        Parallel(Input *, Input *);
		int run();
		Input * left;
		Input * right;
};

#endif
