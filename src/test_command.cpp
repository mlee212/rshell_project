#include "../header/test_command.hpp"

int TestCommand::run() {
	stringstream ss(input);
	vector<string> values;
	string temp;
	while (ss >> temp){
		values.push_back(temp);
//		cout << "temp: " << temp << endl;
	}
//	cout << "size: " << values.size() << endl;
	bool exists = false;
	struct stat statistic;
	//cout << "stat: " << stat(values.at(2).c_str(), &statistic) << endl;
	if (values.at(1) == "-e"){
		if (stat(values.at(2).c_str(), &statistic) == 0) {
			exists = true;
		}
	}
	else if (values.at(1) == "-f") {
		stat(values.at(2).c_str(), &statistic);
		if (S_ISREG(statistic.st_mode)) {
			exists = true;
		}
	}
	else if (values.at(1) == "-d") {
		stat(values.at(2).c_str(), &statistic);
		if (S_ISDIR(statistic.st_mode)) {
			exists = true;
		}
	}
	else {
		if (stat(values.at(1).c_str(), &statistic) == 0) {
			exists = true;
		}
	}
	if (exists){
		cout << "(True)" << endl;
		return 1;
	}
	else {
		cout << "(False)" << endl;
	}
	return -1;	
}	
