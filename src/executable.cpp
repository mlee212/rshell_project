#include "../header/executable.hpp"

//Executable::Executable(string x){ 
//	input = x;
//}

void Executable::run(){
	int space = 0;
	bool quote = false;
	// if there is a space then that means there is an argument in this input);
	for(int i = 0; i < input.size(); i++){
		if (input.at(i) == '\"'){
			quote = !quote;
		}
		if (input.at(i) == ' '){
			space++;
		}
	}
	char * command;
	int index = 0;
	if (space > 0){
		for (int i = 0; i < input.size(); i++){
			if (input.at(i) == ' '){
				int x = i++;
				command = new char[x];
				strcpy(command, input.substr(0, i).c_str());
				for (int j = 0; j < x; j++){
					cout << command[j];
				}
				cout << endl;
				index = i;
				break;
			}
		}
	}
	else {
		command = new char[input.size() + 1];
		strcpy(command, input.c_str());
	}
	
		
	char * arguments[space + 2];
	arguments[0] = command;
	arguments[space + 1] = NULL;
	if (space > 0){
		bool quote = false;
		for (int i = index; i < input.size(); i++){
			int x = 0;
			if (input.at(i) == '\"'){
				quote = !quote;
			}
			if (input.at(i) == ' ' && !quote){
				x = i++ - index;
				strcpy(arguments[i], input.substr(index, x).c_str());
				index = i;
				index++;
			}
			x++;
		}
	}
	for (int i = 0; i < space + 1; i++){
		index = 0;
		while (arguments[i][index] != '\0'){
			cout << arguments[i][index++];
		}
		cout << endl;
	}
	cout << index << endl;
	execvp(command, arguments);
}
