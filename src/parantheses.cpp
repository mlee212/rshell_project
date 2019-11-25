#include "../header/parantheses.hpp"

Parantheses::Parantheses(Input * l) {
    left = l;
}

int Parantheses::run(){
    if (l->run() != -1){
        return 1;
    }
    return -1;
}
