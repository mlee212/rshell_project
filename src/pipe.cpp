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

    cout << "hello1" << endl;
    dup2(x, 1);
    cout << "hello2" << endl;
    if (left->run() == -1){
        return -1;
    }
    cout << "hello3" << endl;
    dup2(savestdout, 1);
    // close(p[1]);
    cout << "hello4" << endl;
    dup2(y, 0);
    cout << "hello5" << endl;
    if (right->run() == -1){
        return -1;
    }
    cout << "hello6" << endl;
    dup2(savestdin, 0);
    // close(p[0]);


    return 1;
}
