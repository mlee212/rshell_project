#define __SEMICOLON_HPP__
#ifndef __SEMICOLON_HPP__
#include "input.hpp"

class Semicolon : public Input {
    public:
        Semicolon(Input *, Input *);
        int run();
        Input * left;
        Input * right;
};

#endif
