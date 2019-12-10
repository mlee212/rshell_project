#ifndef __OUTPUT_REDIRECT_HPP__
#define __OUTPUT_REDIRECT_HPP__

#include "input.hpp"

class OutputRedirection : public Input {
	public:
		OutputRedirection(string x) : Input(x) { };
		int run();
};
