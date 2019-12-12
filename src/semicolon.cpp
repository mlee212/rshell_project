#include "../header/semicolon.hpp"

int Semicolon::run() {
    int l = left->run();
    if (l == 100) {
        exit(1);
    }
    right->run();
    return 1;
}
