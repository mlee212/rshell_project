#include "input_data.hpp"

InputData::InputData(){
	string inp;
	getline(cin, inp);
	
	int beginning_word = 0;

	string str;

	for (int i = 0; i < inp.size(); i++){
		if (inp.at(i) == ' '){
			for(int j = beginning_word; j < i; j++){
				str += inp.at(j);
			}
			if (str == "ls" || str == "echo" || str == "mkdir"){
				inputs.push_back(new Executable(str));
			}
			else {
				inputs.push_back(new Argument(str));
			}
			beginning_word = i + 1;
		}
	}

	for (int i = 0; i < inputs.size(); i++){
		cout << inputs.at(i)->input << " ";
	}
	cout << endl;

}

void InputData::run(){
	// nothing for now
	return;
}

