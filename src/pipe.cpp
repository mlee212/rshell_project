#include "../header/pipe.hpp"

int Pipe::run() {
    // int p[2];
    // cout << "left: " << left->input << endl;
    // cout << "right: " << right->input << endl;
    // if (pipe(p) == -1){
    //     return -1;
    // }
    //
    // int savestdin = dup(0);
    // int savestdout = dup(1);
    // int x = p[1];
    // int y = p[0];
    //
    // cout << "hello1" << endl;
    // dup2(x, 1);
    // cout << "hello2" << endl;
    // if (left->run() == -1) {
    //     return -1;
    // }
    // cout << "hello3" << endl;
    // dup2(savestdout, 1);
    // cout << "hello4" << endl;
    // close(x);
    //
    // cout << "hello5" << endl;
    // dup2(y, 0);
    // cout << "hello6" << endl;
    // if (right->run() == -1) {
    //     return -1;
    // }
    // cout << "hello7: " << endl;
    // dup2(savestdin, 0);
    // cout << "hello8: " << endl;
    // close(y);
    // cout << "hello9: " << endl;

    int p[2];
    int savestdin = dup(0);
    int savestdout = dup(1);
    if (pipe(p) == -1) {
        return -1;
    }
    pid_t pid;
    int stat;
    if ((pid = fork()) == 0){
        dup2(p[1], 1);
        dup2(savestdout, 1);
        close(p[1]);
        if (left->run() == -1) {
            return -1;
        }
    }
    else {
        waitpid(pid, &stat, 0);
        dup2(p[0], 0);
        dup2(savestdin, 0);
        close(p[0]);
        if (right->run() == -1) {
            return -1;
        }
    }

    return 1;
}
