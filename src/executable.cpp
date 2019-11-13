#include "../header/executable.hpp"

//Executable::Executable(string x){ 
//	input = x;
//}

void Executable::run(){
	int space = 0;
	// if there is a space then that means there is an argument in this input);
	for(int i = 0; i < input.size(); i++){
		if (input.at(i) == ' '){
			space++;
		}
	}
	char * command;
	int index = 0;
	if (space > 0){
		for (int i = 0; i < input.size(); i++){
			if (input.at(i) == ' '){
				strcpy(command, input.substr(0, i).c_str());
				index = i;
				break;
			}
		}
	}
	else {
		strcpy(command, input.c_str());
	}
		
	char * arguments[space];
	if (space > 0){
		bool quote = false;
		for (int i = index; i < input.size(); i++){
			if (input.at(i) == '\"'){
				quote = !quote;
			}
			if (input.at(i) == ' ' && !quote){
				strcpy(arguments[i], input.substr(index, i).c_str());
				index = i;
				index++;
			}
		}
	}
	execvp(command, arguments);
}
