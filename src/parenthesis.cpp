#include "../header/parenthesis.hpp"

Parenthesis::Parenthesis(string str) : Input(str) { } 

int Parenthesis::run() {
	string strToParse = input.substr(1, input.size() - 2);
	InputData exeList = InputData(strToParse);
	exeList.takeInput();
	return exeList.run();
}

