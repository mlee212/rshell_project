#ifndef __INPUTS_HPP__
#define __INPUTS_HPP__

#include "input.hpp"

class Inputs : public Input{
	public:
		Inputs();
		void run();
		void setStratExe(StratExe *);
		void setStratCon(StratCon *);
	private:
		vector<Input *> inputs;
		vector<Input *> args;
		StratExe * se;
		StratCon * sc;
};

#endif
