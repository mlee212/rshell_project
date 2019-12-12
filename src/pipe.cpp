#include "../header/pipe.hpp"

int Pipe::run() {
    int p[2];
    int savestdin = dup(0);
    int savestdout = dup(1);

    if (pipe(p) == -1) {
        exit(1);
    }

    dup2(p[1], 1);

    left->run();

    close(p[1]);

    dup2(savestdout, 1);
    dup2(p[0], 0);

    right->run();

    close(p[0]);

    dup2(savestdin, 0);

    return 1;
}
