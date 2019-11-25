#define __PARANTHESES_HPP__
#ifndef __PARANTHESES_HPP__
#include "input.hpp"

class Parantheses : public Input {
    public:
        Parantheses(Input *);
        int run();
        Input * left;
};

#endif
