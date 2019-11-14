#include "../header/executable.hpp"

//Executable::Executable(string x){ 
//	input = x;
//}

int Executable::run(){
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
	char * arguments[space + 2];
	int index = 0;
	int cIndex = 0;
	bool first = false;
	if (space > 0){
		for (int i = 0; i < input.size(); i++){
			if (input.at(i) == '\"'){
				quote = !quote;
			}
			if (input.at(i) == ' ' && !quote){
				//`cout << "cIndex: " << cIndex << endl;
				//cout << "input: " << input.substr(index, i - index) << endl;
				arguments[cIndex] = new char[i - index + 1];
				strcpy(arguments[cIndex++], input.substr(index, i - index).c_str());
				int temp = 0;
				//while(arguments[cIndex - 1][temp] == '\0') {

				//	cout << arguments[cIndex - 1][temp];
				//}
				cout << endl;
				index = i + 1;
			}
		}
		command = arguments[0];
		//cout << "cIndex: " << cIndex << endl;
        //cout << "input: " << input.substr(index, input.size() - 1) << endl;
		arguments[cIndex] = new char[input.size() + 1 - index];
		strcpy(arguments[cIndex], input.substr(index, input.size() - 1).c_str());
		arguments[space + 1] = '\0';
	}
	else {
		command = new char[input.size() + 1];
		strcpy(command, input.c_str());
		arguments[0] = command;
		arguments[1] = NULL;
	}
	
	//for (int i = 0; i < space + 1; i++){
	//	index = 0;
		//while (arguments[i][index] != '\0'){
		//	cout << arguments[i][index++];
		//}
		//cout << endl;
	//}
	return execvp(command, arguments);
}
