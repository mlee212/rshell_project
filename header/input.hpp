#ifndef __INPUTS_HPP__
#define __INPUTS_HPP__

#include <iostream>
#include <string>

class Input {
	protected:
		string input;
	public:
		Input(string);
		virtual void run() = 0;
}

#endif
