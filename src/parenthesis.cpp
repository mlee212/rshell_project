#include "../header/parenthesis.hpp"

Parenthesis::Parenthesis(string str) : Input(str) { } 

int Parenthesis::run() {
	string strToParse = input;
	while (strToParse.at(0) == '(' && strToParse.at(input.length() - 1) == ')') {
		strToParse = strToParse.substr(1, input.size() - 2);
	}	
//	string strToParse = input.substr(1, input.size() - 2);
	cout << "strToParse: " << strToParse << endl;
	InputData exeList = InputData(strToParse);
	exeList.takeInput();
	return exeList.run();
}

