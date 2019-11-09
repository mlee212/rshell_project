#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

#include "input.hpp"

class Executable : public Input {
	public:
		Executable(string);
		void run();

};

#endif
