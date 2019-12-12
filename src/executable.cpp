#include "../header/executable.hpp"

//Executable::Executable(string x){
//	input = x;
//}

int Executable::run(){
	int space = 0;
	bool quote = false;
	bool inputr = false;
	int outputr = 0;
	// if there is a space then that means there is an argument in this input);
	for(int i = 0; i < input.size(); i++){
		if (input.at(i) == '\"'){
			quote = !quote;
		}
		if (input.at(i) == ' ' && !quote){
			space++;
		}
		if (input.at(i) == '>' && !quote) {
			if (i != input.size() - 1){
				if (input.at(i + 1) == '>') {
					input.erase(i - 1, 3);
					outputr = 2;
				}
				else {
					input.erase(i - 1, 2);
					outputr = 1;
				}
			}
		}
		if (input.at(i) == '<' &&  !quote) {
			input.erase(i - 1, 2);
			inputr = true;
		}
	}
	cout << "." << input << "." << endl;
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
				//cout << endl;
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
	//	while (arguments[i][index] != '\0'){
	//		cout << arguments[i][index++];
	//	}
		//cout << i << endl;
	//}
	string exitTest = command;
	cout << "input: " << input << endl;
	if (exitTest == "exit"){
		return 100;
	}
	if (inputr) {
		int file = open(arguments[space], O_RDONLY);
		dup2(file, 0);
		arguments[space] = '\0';
		// execvp(command, arguments);
		// return file;
		//close(file);
	}
	else if (outputr == 1) {
		//cout << "arguments size: " << space + 2 << endl;
		//cout << "filename: " << arguments[space + 1]  << endl;
		int file = open(arguments[space] ,  O_WRONLY | O_CREAT, 0644);
		dup2(file, 1);
		arguments[space] = '\0';
		// execvp(command, arguments);
		// return file;
		//cout << "hello" << endl;
		//printf("test");
		//close(file);
	}
	else if (outputr == 2) {
		int file = open(arguments[space], O_WRONLY | O_APPEND | O_CREAT, 0644);
		dup2(file, 1);
		arguments[space] = '\0';
		// execvp(command, arguments);
		// return file;
		//close(file);
	}
	pid_t p;
	int stat;
	for (int i = 0; i < strlen(arguments); i++){
		cout << "arguments[" << i << "]: " << arguments << endl;
	}
	if ((p = fork()) = 0) {
		cout << "This is child process" << endl;
		int leave = execvp(command, arguments);
		cout << leave << endl;
		exit(leave);
	}
	else {
		cout << "This is parent process" << endl;
		pid_t test = waitpid(p, &stat, 0);
		if (WIFEXITED(stat)){
			if (WEXITSTATUS(stat) == 2){
				return -1;
			}
			else if (WEXITSTATUS(stat) == 1){
				return 1;
			}
		}
	}
	return 1;
}
