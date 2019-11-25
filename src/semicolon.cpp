#include "../header/semicolon.hpp"

Semicolon::Semicolon(Input * l, Input * r) {
    left = l;
    right = r;
}

int Semicolon::run(){
    left->run();
    right->run();
    return 1;
}
