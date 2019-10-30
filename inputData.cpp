#include "InputData.hpp"

InputData::InputData() {
	string str;
	string temp;
	vector<string> tempV;
	getline(cin, str);
	int argSwitch = 1;
	
	while (cin >> temp) {
		std::inputs.push_back(temp);
		if(argSwitch % 2 == 0) {
			std::tempV.push_back(temp);
		}
		argSwitch++;
	}
	
	for(int i = 0; i < tempV.size(); i++) {
		if(tempV.at(i) == '|'{
			
			
		}
		
	}
	
	
}
