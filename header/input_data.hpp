#ifndef __INPUT_DATA_HPP__
#define __INPUT_DATA_HPP__

#include "inputs.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

class InputData : public Input {
	public:
		vector<string> inputs;
		string tempStr;
	public:
		InputData(string);
		void takeInput();
		void run();
};
#endif