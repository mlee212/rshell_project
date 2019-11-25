#include "../header/parallel.hpp"

Parallel::Parallel(Input * l, Input * r) {
    left = l;
    right = r;
}

int Parallel::run(){
    if (left->run() == -1){
        right->run();
        return 1;
    }
    return -1;
}
