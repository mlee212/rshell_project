#include <iostream>
#include "../header/input.hpp"
#include "../header/executable.hpp"

using namespace std;

int main(){
	//Input * x = new Executable("ls");
	//x->run();

	Input * y = new Executable("ls -a");
	y->run();
}
