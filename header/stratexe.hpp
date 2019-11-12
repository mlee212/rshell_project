#ifndef __STRATEXE_HPP__
#define __STRATEXE_HPP__

#include "inputs.hpp"

class StratExe {
	public:
		virtual void run(vector<Argument *>) = 0;
	protected:
		Inputs * inp;
};



#endif
