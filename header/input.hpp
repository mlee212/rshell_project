#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <string>

using namespace std;

class Input{
	public:
		Input(string x);	
		virtual void run() = 0;
	protected:
		string input;

};

#endif
