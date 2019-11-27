#include "../header/parenthesis.hpp"

Parenthesis::Parenthesis(string str) : Input(str) { } 

int Parenthesis::run() {
	int i = 0;
	string strToParse = input;
//	cout << "strToParse length: " << strToParse.length() << endl;
//	cout << "strToParse: " << strToParse << endl;
//	cout << input.substr(0, 1) << endl;
	while (strToParse.at(0) == '(' && strToParse.at(strToParse.length() - 1) == ')') {
//		cout << i << endl;
		strToParse = strToParse.substr(1, strToParse.length() - 2);
		i++;
	}	
	//string strToParse = input.substr(1, input.size() - 2);
//	cout << "strToParse: " << strToParse << endl;
	InputData exeList = InputData(strToParse);
	exeList.takeInput();
	return exeList.run();
}

