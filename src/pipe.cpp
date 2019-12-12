#include "../header/pipe.hpp"

int Pipe::run() {
    int p[2];

    if (pipe(p) == -1){
        return -1;
    }

    int savestdin = dup(0);
    int savestdout = dup(1);
    int x = p[1];
    int y = p[0];

    cout << "hello1 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    dup2(x, 1);
    cout << "hello2 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    if (left->run() == -1){
        return -1;
    }
    cout << "hello3 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    dup2(savestdout, 1);
    close(x);
    cout << "hello4 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    dup2(y, 0);
    cout << "hello5 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    if (right->run() == -1){
        return -1;
    }
    cout << "hello6 dup(0): " << dup(0) << " dup(1): " << dup(1) << endl;
    dup2(savestdin, 0);
    close(y);


    return 1;
}
