#include "../header/input_data.hpp"
#include <iostream>
#include <string>

int main() {
	string str;
	cout << "$ ";
	getline(cin, str);
	
	InputData inp(str);
	inp.takeInput();

	inp.run();	
	
	return 0;
} 
