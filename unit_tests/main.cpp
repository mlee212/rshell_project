#include <iostream>
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/test.hpp"

using namespace std;

int main(){
	//Input * x = new Executable("ls");
	//x->run();

	//Input * y = new Executable("ls -a");
	//y->run();

	//Input * z = new Executable("echo \"hello world\"");
	//z->run();
	
	Input * l = new Test("test -e header");
	
	Input * m = new Test("test -e rshell");
	m->run();
	
	Input * n = new Test("test -e 5shell");
	n->run();

	Input * o = new Test("test -f rshell");
	o->run();

	Input * p = new Test("test -d rshell");
	p->run();

	Input * q = new Test("test -d header");
	q->run();

	Input * r = new Test("test header");
	r->run();

	Input * s = new Test("test rshell");
	s->run();

	Input * t = new Test("test 5shell");
	t->run();


}

