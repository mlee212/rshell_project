#include "../header/parallel.hpp"

int Parallel::run() {
    int l = left->run();
    if (l == 100) {
        exit(1);
    }
    if (l == -1){
        right->run();
        return 1;
    }
    return -1;
}
