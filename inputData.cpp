#include "InputData.hpp"

InputData::InputData() {
	string str;
	string temp;
	vector<string> tempI;
	vector<string> tempV;
	vector<string> tempC;
	getline(cin, str);
	int argSwitch = 1;
	
	while (cin >> temp) {
		std::tempI.push_back(temp);
		if(argSwitch % 2 == 0) {
			std::tempV.push_back(temp);
		}
		else {
			std::tempI.push_back(temp);
		}
		argSwitch++;
	}
	
	for(int i = 0; i < tempV.size(); i++) {
		if(std::tempV.at(i) == ';' || std::tempV.at(i) == '&' || std::tempV.at(i) == '|'){
			std::args.push_back(std::substr(std::tempV.at(i), 0, std::tempV.at(i).size() - 1);
			std::tempC.push_back(std::tempV.at(i).at(std::tempV.size()));
		}
	}
	
	for(int i = 0; i < std::tempV.size(); i++) {
		std::inputs.push_back(std::tempI.at(i));
		std::inputs.push_back(std::args.at(i));
		std::inputs.push_back(std::tempC.at(i));
	}
	
}
