#include "../header/outputredirection.hpp"
#include "../header/executable.hpp"

int OutputRedirection::run() {
    int savestdout = dup(1);
    left = new Executable(input);
    int file = open(right->input.c_str(),  O_WRONLY | O_CREAT | O_TRUNC, 0664);
    dup2(file, 1);
    if (left->run() == -1){
        return -1;
    }
    dup2(savestdout, 1);
    return 1;
}
