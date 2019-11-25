#include "../header/ampersand.hpp"

Ampersand::Ampersand(Input * l, Input * r) {
    left = l;
    right = r;
}

int Ampersand::run(){
    if (left->run() != -1){
        right->run();
        return 1;
    }
    return -1;
}
