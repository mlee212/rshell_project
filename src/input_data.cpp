#include "../header/input_data.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "../header/input.hpp"
#include "../header/parenthesis.hpp"
//#include "../header/ampersand.hpp"
//#include "../header/parallel.hpp"
//#include "../header/semicolon.hpp"
#include "../header/square.hpp"
#include "../header/test_command.hpp"



void InputData::takeInput() {
	
	
	bool quote = false;
	int numSpaceAdds = 0;
	// modifies the inputted string to isolate semicolons and comments

	for(int i = 0; i < str.size(); i++) {
	//	quote boolean switch to ignore text inside the quotes
		if(str.at(i) == '\"') {
			quote = !quote;
		}
		if (str.at(i) == ';' && !quote) {
			str.insert(i," ");
			i++;
			numSpaceAdds++;
		}
		if (str.at(i) == '#' && i != 0 && !quote) {
			str.insert(i, " ");
			i++;
			str.insert(i + 1, " ");
			i++;
			numSpaceAdds += 2;
		}
			
	}
	string quoteStr = str;
	
	int indexS = 0;
	int indexE = 0;
	int exeLength = 0;
	string temp;
	quote = false;
	int paren = 0;
	int square = 0;
	bool parenE = false;
	bool quoteSec = false;
	bool quit = false;
	bool quitCheck = false;
	bool start = true;
	string quitStr;
	bool startsq = false;
	bool sqExist = false;
	bool inTest = false;
	int numParamSq = 0;
	int tempIndSq = 0;
	bool testStart = false;
	int numArgs = 0;
	bool firstArgRun = true;

	// run string through a stringstream where each piece of text is separated by space.
	
	stringstream ss(str);
	while(ss >> temp && !quitCheck) {
		if(!quote) {
			numArgs++;
		}
		// determines whether the executable is of test command	
		if(!quote && !paren && !square && !inTest && temp == "test") {
			indexE++;
			exeLength++;
			inTest = true;
			testStart = true;
		}
		// determines whether there is a quote, parenthesis, or square brackets within current string
		for(int i = 0; i < temp.size(); i++) {
			if (temp.at(i) == '\"') {
				quote = !quote;
			}
			if(temp.at(i) == '(' && !quote) {
				parenE = true;
				paren++;
			}
			if(temp.at(i) == ')' && !quote) {
				parenE = true;
				paren--;
			}
			if(temp == "[" && !quote) {
				square++;
				startsq = true;
			}
		}
		if(square > 0) {
			cout << "Square Length: " << square << endl;
			if(startsq) {
//				cout  << "First Square Bracket Read in" << endl;
				tempIndSq = indexE;
				while(str.at(tempIndSq) != ']') {
					if(str.at(tempIndSq) == ' ') {
						numParamSq++;
					}
					tempIndSq++;
				}
//				cout << "tempIndSq: " << tempIndSq << endl;
//				cout << "numParamSq: " << numParamSq << endl;

					if(numParamSq == 2) {
	//				Covers case of 1 space
//						cout << "Are we there yet?" << endl;
						indexE += 2;
						exeLength += 2;
					}
					else {
	//				Cover case of 2 spaces
						indexE += 3;
						exeLength += 3;
					}
			}
			else {
//				cout << "Still in the Square Bracket" << endl;
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				}
				if(temp == "]" && !quote) {
					square--;
				}
			}
			startsq = false;
			
		}
		else if(quote){
	//		cout << "In quote" << endl;
			for(int i = 0; i < temp.size(); i++) {
				indexE++;
				exeLength++;
			}
			indexE += 1;
			exeLength += 1;
		}
		else if(paren > 0){
//			cout << "Num of Open Paren: " << paren << endl;
			if(start) {
//				cout << "First Parenthesis Read in" << endl;
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				}
			}
			else {
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				}
				indexE += 1;
				exeLength += 1;
			}
			start = false;
		} 
		else {
			for(int i = 0; i < temp.size(); i++) {
				indexE++;
				exeLength++;
				if(temp.at(i) == '#') {
					quit = true;
					break;
				}
			}
			if(inTest && testStart) {
	//			Adjusts the executable for special case Test command
//				cout << "Test Command Start" << endl;
				indexE -= 3;
				exeLength -= 3;
				testStart = false;
			}
			else if(inTest) {
//				cout << "Still in Test Command" << endl;
				indexE++;
				exeLength++;
	}
			
	//		Checks if the Connector is of &&, ||, ; type	
			if((temp == "&&")  && !quote) {
				numArgs--;
//				cout << "Char at indexS: " << str.at(indexS) << endl;
//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
//				cout << "numArgs: " << numArgs << endl;
				
				if(numArgs == 1){
					indexE--;
					exeLength--;
				}
	//			Creates Executable Object
				inputs.push_back(new Executable(str.substr(indexS, --exeLength)));
			//	if(str.substr(indexS, --exeLength) == "ls") {
	//			Adjusts the creation of the Connector in the case of Executable is ls
			//		indexE--;
			//		inputs.push_back(new Connector(str.substr(--indexE, temp.size())));
			//	}
			//	else {
	//			Creates the Connector in a normal case
					inputs.push_back(new Connector(str.substr(indexE, temp.size())));
			//	}
				
	//			Reset Parameters
				if(numArgs == 1) {
					indexE++;
				}
				exeLength = 0;
				indexS = indexE + /* 3 */ numArgs + 1;
				indexE = indexS;
				inTest = false;
				numArgs = 0;
				numParamSq = 0;
			}
			else if(temp == "||" && !quote) {
				numArgs--;
//				cout << "Char at indexS: " << str.at(indexS) << endl;
//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
//				cout << "numArgs: " << numArgs << endl;
				
				if(numArgs == 1){
					indexE--;
					exeLength--;
				}

	//			Creates Executable Object
				inputs.push_back(new Executable(str.substr(indexS, --exeLength)));
				if(str.substr(indexS, --exeLength) == "ls" || str.substr(indexS, --exeLength) == "exit") {
	//				Adjusts the creation of the Connector in the case of Executable is ls
					inputs.push_back(new Connector(str.substr(--indexE, temp.size())));
				}
				else {
	//				Creates the Connector in a normal case
					inputs.push_back(new Connector(str.substr(indexE, temp.size())));
				}

	//			Reset Parameters
				if(numArgs == 1) {
					indexE++;
				}
				exeLength = 0;
				indexS = indexE + /* 3 */ numArgs + 1;
				indexE = indexS;
				inTest = false;
				numArgs = 0;
				numParamSq = 0;
			}
			else if(temp == ";"  && !quote ) {
				numArgs--;
//				cout << "Char at indexS: " << str.at(indexS) << endl;
//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
//				cout << "numArgs: " << numArgs << endl;
				
				if(numArgs == 1){
					indexE--;
					exeLength--;
				}

	//			Creates Executable Object
				inputs.push_back(new Executable(str.substr(indexS, exeLength)));
	//			Creates Connector in the case of Semicolon
				inputs.push_back(new Connector(str.substr(indexE + 1, temp.size() /* + 1 */)));

	//			Reset Parameters
				if(numArgs == 1) {
					indexE++;
				}
				exeLength = 0;
				indexS = indexE + /* 3 */ numArgs + 1;
				indexE = indexS;
				inTest = false;
				numArgs = 0;
				numParamSq = 0;
			}
			else if(temp == "|" && !quote) {
	//			Adjusts to fit the amount of Spaces
				if(firstArgRun) {
					exeLength++;
					indexE++;
				}
		//		exeLength++;
		//		indexE++;
		//		exeLength--;

//				cout << "num spaces before: " << numArgs << endl;
				numArgs--;
//				cout << "num spaces after: " << numArgs << endl;

//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
	//			Creates Executable Object
					inputs.push_back(new Executable(str.substr(indexS, exeLength)));
	//			Creates Connector in the case of Pipe
				inputs.push_back(new Connector(str.substr(indexE  + 1 , temp.size())));

	//			Reset Parameters
				exeLength = 0;
				indexS = indexE + numArgs;
				indexE = indexS;
				inTest = false;
				numParamSq = 0;
				numArgs = 0;

				firstArgRun = false;
			}
		//	else if(temp == "<" && !quote) {
		//		exeLength++;
		//		indexE++;
		//	}
			else if(temp == "<" && !quote) {
		//		exeLength++;
		//		indexE++;
			}
			else if(temp == "tee" && !quote) {
				numArgs++;
			}
		//	else if(temp == "ls" && !quote) {
		//		numArgs--;
		//	}
			else if(temp == "tr" && !quote) {
//				cout << "exeLength on tr: " << exeLength << endl;
//				cout << "indexE on tr: " << indexE << endl;
				exeLength++;
				indexE++;
		//		numArgs--;
			}
			else if(temp == ">" && !quote) {
		//		exeLength++;
		//		indexE++;
			}
			else if(temp == "#"  && !quote ) {
				numArgs--;
	//			Creates Executable Object
//				cout << "numArgsCom: " << numArgs << endl;
				if(numArgs == 1) {
					inputs.push_back(new Executable (str.substr(indexS, exeLength - 1)));
				}
				else {
					inputs.push_back(new Executable (str.substr(indexS, exeLength)));
				}
				
	//			Reset Parameters
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
				quitCheck = true;
				inTest = false;
				numParamSq = 0;
			}
		}
	}
	
	// Reuse of Variables
	bool closedP = false;
	paren = 0;
	// Adjusting for added spaces
	indexE += numSpaceAdds;
//	cout << "final index: " << indexE << endl;
//	cout << "str length: " << str.length() << endl;
	
	cout << endl;
	
	// Covers end case within the string
	if (!quitCheck) {
		inputs.push_back(new Executable(str.substr(indexS, indexE + 2)));
	}

	//cout << "Exe + args: " << str.substr(indexS, indexE) << endl;
	// -------------- TEST -----------------------
	//cout << "hello" << endl;
	//cout << indexE << endl;
	//cout << str.size() - 1<< endl;	
	
//	cout << endl << "FINAL DISPLAY" << endl;
	
	for(int i = 0; i < inputs.size(); i++) {
//		cout << endl << "vector: ." << inputs.at(i)->input << "." << endl;
		if(inputs.at(i)->input.at(0) == '(' /*&& inputs.at(i)->input.at(input.length() - 1) == ')'*/) {
//			cout << "Paren Conversion" << endl;
			inputs.at(i) = new Parenthesis(inputs.at(i)->input);
		}
		else if(inputs.at(i)->input.at(0) == '[') {
//			cout << "Square Conversion" << endl;
//			cout << "input length: " << inputs.at(i)->input.length() - 1;
			inputs.at(i) = new Square(inputs.at(i)->input.substr(2, inputs.at(i)->input.length() - 4  ));
		}
		else if(inputs.at(i)->input.length() > 4) {
			if(inputs.at(i)->input.substr(0, 4) == "test") {
//				cout << "Test Conversion" << endl;
				inputs.at(i) = new TestCommand(inputs.at(i)->input); 
			}
		}
//		cout << "And we outta there" << endl;
//		cout << "After: " << inputs.at(i)->input << endl;
		
	}
//	cout << "size: " << inputs.size() << endl;
//	cout << "inputs size: " << inputs.size() << endl;
	
}

int InputData::run() {
	bool next = true;
	int stat;
	bool inputr = false;
	int outputr = 0;
	int p[2];
	int savestdin = dup(0);
	int savestdout = dup(1);
	if (pipe(p) < 0) {
		exit(1);
	}
	pid_t pid[inputs.size()];
	for (int i = 0; i < inputs.size(); i++)	{
		//cout << i << endl;
		if (i % 2 == 1){
			if ((pid[i] = fork()) == 0){
				cout << "This is child: " << getpid() << endl;
				savestdin = dup(0);
				savestdout = dup(1);
				if (inputs.at(i - 1)->run() == -1){
					exit(2);
				}
				else if (inputs.at(i - 1)->run() == 100) {
					exit(1000);
				}
				exit(1);
			}
			else {
				cout << "This is parent: " << i << endl;
				pid_t test = waitpid(pid[i], &stat, 0);
				if (i != inputs.size() - 1){
					if (WIFEXITED(stat)){
						cout << "Child: " << test << " / terminated: " << WEXITSTATUS(stat) << endl;
						if (inputs.at(i - 1)->input == "exit") {
							exit(10000);
						}
						else if (inputs.at(i)->input == "&&" || inputs.at(i)->input == "&& "){
							if (WEXITSTATUS(stat) == 2){
								cout << "Skip &&" << endl;
								next = false;
								i += 2;
							}
							else {
								next = true;
								cout << "Went next &&" << endl;
							}
						}
						else if (inputs.at(i)->input == "||" || inputs.at(i)->input == "|| "){
							if (WEXITSTATUS(stat) != 2){
								cout << "Skip || " << WEXITSTATUS(stat) << endl;
								next = false;
								i += 2;
							}
							else {
								next = true;
								cout << "Went next ||" << endl;
							}
						}
						else if (inputs.at(i)->input == "|" || inputs.at(i)->input == "| ") {					
						
						}
						else {
							next = true;
							cout << "Went next 3" << endl;
						}
					}
				}
			}
		}
	}
	if (inputs.size() % 2 == 1 && next){
		cout << "next true" << endl;
		pid_t x;
		if ((x = fork()) == 0){
			cout << "child rn" << endl;
			if (inputs.at(inputs.size() - 1)->input == "exit") {
				exit(10000);
			}
			inputs.at(inputs.size() - 1)->run();
		}
		else {
			cout << "parent rn" << endl;
			waitpid(x, & stat, 0);
			if (inputs.at(inputs.size() - 1)->input == "exit") {
				exit(10000);
			}
		}
	}
	else if (inputs.size() == 1){
		pid_t x;
		if ((x = fork()) == 0) {
			cout << "child at end" << endl;
			if (inputs.at(inputs.size() - 1)->input == "exit") {
				exit(10000);
			}
			inputs.at(0)->run();
		}
		else {
			waitpid(x, &stat, 0);
			cout << "parent at end" << endl;
			if (inputs.at(inputs.size() - 1) ->input == "exit") {
				exit(10000);
			}
		}
	}
	dup2(savestdin, 0);
	dup2(savestdout, 1);
	return 0;
}

