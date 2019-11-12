#ifndef __STRATCON_HPP__
#define __STRATCON_HPP__

#include "inputs.hpp"

class StratCon {
	public:
		virtual void run() = 0;
	protected:
		Inputs * inp;
};



#endif
