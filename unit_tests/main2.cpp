#include "input_data.hpp"
#include <iostream>
#include <string>

int main() {
	string str;
	cout << "$";
	getline(cin, str);
	
	InputData inp(str);
	
	
	return 0;
} 
