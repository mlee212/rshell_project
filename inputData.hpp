#ifndef __INPUT_DATA_HPP__
#define __INPUT_DATA_HPP__

#include "inputs.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

class InputData : public Input {
	protected:
		vector<Input *> inputs;
		vector<Input *> args;
	public:
		InputData() : Input() { };
		virtual void run() = 0;

#endif
