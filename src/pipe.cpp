#include "../header/pipe.hpp"

int Pipe::run() {
    int p[2];

    if (pipe(p) == -1){
        return -1;
    }

    int savestdin = dup(0);
    int savestdout = dup(1);

    dup2(p[1], 1);

    if (left->run() == -1){
        return -1;
    }

    dup2(savestdout, 1);
    close(p[1]);

    dup2(p[0], 0);

    if (right->run() == -1){
        return -1;
    }

    dup2(savestdin, 0);
    close(p[0]);


    return 1;
}
