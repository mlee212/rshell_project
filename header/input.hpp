#ifndef __INPUTS_HPP__
#define __INPUTS_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <vector>
#include <unistd.h>


using namespace std;

class Input {
	public:
		string input;
		Input(string);
		virtual int run() = 0;
};

#endif
