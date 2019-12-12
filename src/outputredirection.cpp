#include "../header/outputredirection.hpp"

int OutputRedirection::run() {
    int savetstdout = dup(1);
    int file = open(right->input ,  O_WRONLY | O_CREAT | O_TRUNC, 0664);
    dup2(file, 1);
    if (left->run() == -1){
        return -1;
    }
    dup2(savestdout, 1);
    return 1;
}
