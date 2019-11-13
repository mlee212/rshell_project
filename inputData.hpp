#ifndef __INPUT_DATA_HPP__
#define __INPUT_DATA_HPP__

//#include "inputs.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class InputData /* : public Input */ {
	protected:
		vector<string> inputs;
		string tempStr;
	public:
		InputData();
		void takeInput();
		//virtual void run() = 0;
};
#endif
