#include "../header/parantheses.hpp"

Parantheses::Parantheses(Input * l, Input * r) {
    left = l;
    right = r;
}

int Parantheses::run(){
    if (left->run() == -1){
        right->run();
        return 1;
    }
    return -1;
}
