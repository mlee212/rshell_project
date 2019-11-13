#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

class Input{
	public:
		Input(string x);	
		virtual void run() = 0;
	protected:
		string input;

};

#endif
