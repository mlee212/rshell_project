#include <iostream>
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/test_command.hpp"
#include "../header/square.hpp"

using namespace std;

int main(){
	//Input * x = new Executable("ls");
	//x->run();

	//Input * y = new Executable("ls -a");
	//y->run();

	//Input * z = new Executable("echo \"hello world\"");
	//z->run();
	
	Input * l = new TestCommand("test -e header");
	l->run();	

	Input * m = new TestCommand("test -e rshell");
	m->run();
	
	Input * n = new TestCommand("test -e 5shell");
	n->run();

	Input * o = new TestCommand("test -f rshell");
	o->run();

	Input * p = new TestCommand("test -d rshell");
	p->run();

	Input * q = new TestCommand("test -d header");
	q->run();

	Input * r = new TestCommand("test header");
	r->run();

	Input * s = new TestCommand("test rshell");
	s->run();

	Input * t = new TestCommand("test 5shell");
	t->run();

	Input * u = new Square("header");
	u->run();

	Input * w = new Square("u_test.cpp");
	w->run();


}

