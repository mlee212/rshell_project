#define __AMPERSAND_HPP__
#ifndef __AMPERSAND_HPP__
#include "input.hpp"

class Ampersand : public Input {
    public:
        Ampersand(Input *, Input *);
        int run();
        Input * left;
        Input * right;
};

#endif
