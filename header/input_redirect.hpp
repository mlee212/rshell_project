#ifndef __INPUT_REDIRECT_HPP__
#define __INPUT_REDIRECT_HPP__

#include "input.hpp"

class InputRedirection : public Input {
	public:
		InputRedirection(string x) : Input(x) { };
		int run();
};
