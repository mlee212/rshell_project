#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <string>
using namespace std;

class Input {
	public:
		Input() { this->input = ""; };
		Input(string str) { this->input = str; };
		virtual void run() = 0;
		string input;
};

#endif
