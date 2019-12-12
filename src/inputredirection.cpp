#include "../header/inputredirection.hpp"
#include "../header/executable.hpp"

int InputRedirection::run() {
    int savestdin = dup(0);
    left = new Executable(left->input + " " + right->input);
    int file = open(right->input, O_RDONLY | O_EXCL);
    if (file == -1) {
        return -1;
    }
    dup2(file, 0);
    if (left->run() == -1){
        return -1;
    }
    dup2(savestdin, 0);

    return 1;
}
