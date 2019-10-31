#ifndef __INPUT_DATA_HPP__
#define __INPUT_DATA_HPP__

#include "input.hpp"
#include "executable.hpp"
#include "argument.hpp"
#include <iostream>
#include <string>
#include <vector>

class InputData : public Input {
	public:
		InputData();
		void run();
	private:
		vector<Input *> inputs;
		vector<Input *> args;
};

#endif
