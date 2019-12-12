#include "../header/pipe.hpp"

int Pipe::run() {
    int p[2];
    int savestdin = dup(0);
    int savestdout = dup(1);

	cout << "cin: " << savestdin << endl;
	cout << "cout: " << savestdout << endl;

    if (pipe(p) == -1) {
        exit(1);
    }

    dup2(p[1], 1);

    cout << "left: " << left->input << endl;
    left->run();
    cout << "after left ran" << endl;
	dup2(savestdout, 1);
    close(p[1]);
	dup2(savestdout, 1);

	dup2(p[0], 0);

    cout << "right: " << right->input << endl;
    right->run();
    cout << "after right ran" << endl;
	dup2(savestdin, 0);
    close(p[0]);
	dup2(savestdin, 0);

	dup2(savestdout, 1);
    dup2(savestdin, 0);

	int temp1 = dup(0);
	int temp2 = dup(1);

	cout << "temp1: " << temp1 << endl;
	cout << "temp2: " << temp2 << endl;

    return 1;
}
