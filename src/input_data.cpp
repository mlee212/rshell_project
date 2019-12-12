#include "../header/input_data.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "../header/input.hpp"
#include "../header/parenthesis.hpp"
#include "../header/ampersand.hpp"
#include "../header/parallel.hpp"
#include "../header/semicolon.hpp"
#include "../header/square.hpp"
#include "../header/test_command.hpp"



/*void InputData::takeInput() {


	bool quote = false;
	//int numSpaceAdds = 0;
	// modifies the inputted string to isolate semicolons and comments

	for(int i = 0; i < str.size(); i++) {
	//	quote boolean switch to ignore text inside the quotes
		if(str.at(i) == '\"') {
			quote = !quote;
		}
		if (str.at(i) == ';' && !quote) {
			str.insert(i," ");
			i++;
			//numSpaceAdds++;
		}
		if (str.at(i) == '#' && i != 0 && !quote) {
			str.insert(i, " ");
			i++;
			str.insert(i + 1, " ");
			i++;
			//numSpaceAdds += 2;
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
	bool correctParamPiping = false;

	// run string through a stringstream where each piece of text is separated by space.

	stringstream ss(str);
	while(ss >> temp && !quitCheck) {
		cout << "beginning indexE: " << indexE << endl;
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
<<<<<<< HEAD:src/Binput_data.cpp
				if(numArgs == 1) {
					indexS = indexE + * 3 *//* numArgs + 1; ---------------------------------------------------------------------------------------------------
				}
				else if(numArgs > 1) {
					indexS = indexE + 3;
				}
=======
				indexS = indexE +  3  numArgs + 1;
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp
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
<<<<<<< HEAD:src/Binput_data.cpp
		//		if(numArgs == 1) {
					indexS = indexE +  3 * numArgs + 1;
		//		}
		//		else if(numArgs > 1) {
		//			indexS = indexE + 3;
		//		}
=======
				indexS = indexE +  3  numArgs + 1;
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp
				indexE = indexS;
				inTest = false;
				numArgs = 1;
				numParamSq = 0;
			}
			else if(temp == ";"  && !quote ) {
				numArgs--;
//				cout << "Char at indexS: " << str.at(indexS) << endl;
//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
//				cout << "numArgs: " << numArgs << endl;

				//if(numArgs == 1){
				//	indexE--;
				//	exeLength--;
				//}
				if(!firstArgRun) {
					indexS--;
					indexE--;
				}
	//			Creates Executable Object
				inputs.push_back(new Executable(str.substr(indexS, exeLength)));
	//			Creates Connector in the case of Semicolon
<<<<<<< HEAD:src/Binput_data.cpp

				inputs.push_back(new Connector(str.substr(indexE + 1, temp.size() * + 1 *)));
=======
				inputs.push_back(new Connector(str.substr(indexE + 1, temp.size()  + 1 )));
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp

	//			Reset Parameters
				if(numArgs == 1) {
					indexE++;
				}
				exeLength = 0;
				indexS = indexE +  3  numArgs + 1;
				indexE = indexS;
				inTest = false;
				numArgs = 0;
				numParamSq = 0;
			}
			else if(temp == "|" && !quote) {
				cout << "RIGHT Before: " << indexE << endl;
				cout << "RIGHT Before length: " << exeLength << endl;
	//			Adjusts to fit the amount of Spaces
				if(!firstArgRun) {
			//		numArgs++;
			//		indexE++;
				}
				if(firstArgRun) {
					exeLength++;
			//		indexE++;
				}
				cout << "RIGHT After: " << indexE << endl;
				cout << "Right After length: " << exeLength << endl;
		//		exeLength++;
		//		indexE++;
		//		exeLength--;

//				cout << "num spaces before: " << numArgs << endl;
				numArgs--;
<<<<<<< HEAD:src/Binput_data.cpp
				cout << "num spaces after: " << numArgs << endl;

				if(numArgs < 4 && !firstArgRun) {
					exeLength--;
					correctParamPiping = true;
				}
			//	else if(numArgs < 3 && !firstArgRun) {
			//		exeLength++;
			//	}

				if(numArgs < 4 && !firstArgRun) {
					indexE--;
				}



				cout << "indexE with hardcode: " << indexE + 3 << endl;
				cout << "indexE with numArgs: " << indexE + numArgs << endl;
				cout << "indexE: " << indexE << endl;
				cout << "exeLength: " << exeLength << endl;
				cout << "substr length: " << str.substr(indexS, exeLength).length() << endl;
				cout << "substr: " << str.substr(indexS, exeLength) << endl;
				cout << "Connector run: inputs.push_back(new Connector(str.substr(" << indexE + 1 << "," << temp.size() << ")))" << endl;
=======
//				cout << "num spaces after: " << numArgs << endl;

//				cout << "indexE with hardcode: " << indexE + 3 << endl;
//				cout << "indexE with numArgs: " << indexE + numArgs << endl;
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp
	//			Creates Executable Object
					inputs.push_back(new Executable(str.substr(indexS, exeLength)));
	//			Creates Connector in the case of Pipe
			//	if(firstArgRun) {

					indexE++;
					inputs.push_back(new Connector(str.substr(indexE + 1, temp.size())));
			//	}
			//	else {
			//		inputs.push_back(new Connector(str.substr(indexE + 1, temp.size())));
			//	}
				if(numArgs == 3 && !firstArgRun) {
					indexE--;
				}
				if(correctParamPiping) {
					indexE--;
					correctParamPiping = false;
				}

	//			Reset Parameters
				exeLength = 1;
				if(numArgs == 4 && !firstArgRun) {
					indexS = indexE + numArgs - 1;
					indexE = indexS;

				}
				else {
					indexS = indexE + numArgs;
					indexE = indexS;
				}
				inTest = false;
				numParamSq = 0;
				numArgs = 1;

				firstArgRun = false;
				cout << "letter at indexS: " << str.at(indexS) << endl;
				cout << "letter at indexS + 1: " << str.at(indexS + 1) << endl;

			}
		//	else if(temp == "<" && !quote) {
		//		exeLength++;
		//		indexE++;
		//	}
			else if(temp == ">>" && !quote) {
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				}

		//		numArgs += 2;
		//		exeLength += 2;
		//		indexE += 2;
			}
			//else if(temp == "<" && !quote) {
		//		exeLength++;
		//		indexE++;
			//}
		//	else if(temp == "tee" && !quote) {
		//		numArgs++;
		//	}
		//	else if(temp == "ls" && !quote) {
		//		numArgs--;
		//	}
<<<<<<< HEAD:src/Binput_data.cpp
		//	else if(temp == "tr" && !quote) {
		//		cout << "exeLength on tr: " << exeLength << endl;
		//		cout << "indexE on tr: " << indexE << endl;
		//		exeLength++;
		//		indexE++;
=======
			else if(temp == "tr" && !quote) {
//				cout << "exeLength on tr: " << exeLength << endl;
//				cout << "indexE on tr: " << indexE << endl;
				exeLength++;
				indexE++;
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp
		//		numArgs--;
		//	}
			//else if(temp == ">" && !quote) {
		//		exeLength++;
		//		indexE++;
			//}
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
<<<<<<< HEAD:src/Binput_data.cpp
	numArgs--;
	indexE += numArgs;
	cout << "Last numArgs" << numArgs << endl;
	cout << "final index: " << indexE << endl;
	cout << "str length: " << str.length() << endl;
=======
	indexE += numSpaceAdds;
//	cout << "final index: " << indexE << endl;
//	cout << "str length: " << str.length() << endl;
>>>>>>> e1618a36c1f28d36be6d8fa1fb4c97846b6b2da1:src/input_data.cpp

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
		if(inputs.at(i)->input.at(0) == '(' && inputs.at(i)->input.at(input.length() - 1) == ')') {
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
*/

void InputData::takeInput(){
	bool quote = false;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '\"') {
			quote = !quote;
		}
		if (str.at(i) == ';' && !quote) {
			str.insert(i++, " ");
		}
		if (str.at(i) == '#' && i != 0 && !quote) {
			str.insert(i++, " ");
			str.insert(++i, " ");
			i++;
		}
	}
	int indexS = 0;
	int indexE = 0;
	int paren = 0;
	bool square;
	bool quitCheck = false;
	quote = false;
	string temp;
	stringstream ss(str);
	cout << str << endl;
	while (ss >> temp && !quitCheck) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp.at(i) == '\"') {
				quote = !quote;
			}
			else if (temp.at(i) == '(') {
				paren++;
			}
			else if (temp.at(i) == ')') {
				paren--;
			}
		}
		if (temp == "&&" && !quote && !paren) {
			inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
			indexS = indexE;
			inputs.push_back(new Connector(str.substr(indexS, 2)));
			indexS += 3;
			indexE = indexS;
		}
		else if (temp == "||" && !quote && !paren) {
			inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
			indexS = indexE;
			inputs.push_back(new Connector(str.substr(indexS, 2)));
			indexS += 3;
			indexE = indexS;
		}
		else if (temp == ";" && !quote && !paren) {
			inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
			indexS = indexE;
			inputs.push_back(new Connector(str.substr(indexS, 1)));
			indexS += 2;
			indexE = indexS;
		}
		else if (temp == "#" && !quote && !paren) {
			inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
			indexS = indexE;
			quitCheck = true;
		}
		else if (temp == "|" && !quote && !paren) {
			inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
			indexS = indexE;
			inputs.push_back(new Connector(str.substr(indexS, 1)));
			indexS += 2;
			indexE = indexS;
		}
		else {
			cout << temp << endl;
			indexE += temp.size() + 1;
		}
	}
	if (!quitCheck) {
		inputs.push_back(new Executable(str.substr(indexS, indexE - indexS - 1)));
	}
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i)->input.at(0) == '(') {
			inputs.at(i) = new Parenthesis(inputs.at(i)->input);
		}
		else if (inputs.at(i)->input.at(0) == '[') {
			inputs.at(i) = new Square(inputs.at(i)->input.substr(2, inputs.at(i)->input.size() - 4));
		}
		else if (inputs.at(i)->input.size() > 4) {
			if (inputs.at(i)->input.substr(0, 4) == "test") {
				inputs.at(i) = new TestCommand(inputs.at(i)->input);
			}
		}
	}
	for (int i = 0; i < inputs.size(); i++) {
		cout << "input[" << i << "] = ." << inputs.at(i)->input << "." << endl;
	}
	// echo a && echo b && echo c

}

int InputData::run() {
	auto it = inputs.begin();

	while (it != inputs.end()){
		if (*it->input == "&&") {
			Input * temp = new Ampersand("&&", inputs.at(0), inputs.at(2));
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.insert(inputs.begin(), temp);
		}
		else if (*it->input == "||") {
			Input * temp = new Parallel("||", inputs.at(0), inputs.at(2));
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.insert(inputs.begin(), temp);
		}
		else if (*it->input == ";") {
			Input * temp = new Semicolon(";", inputs.at(0), inputs.at(2));
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.erase(inputs.begin());
			inputs.insert(inputs.begin(), temp);
		}
		else {
			it++;
		}
	}

	for (int i = 0; i < inputs.size(); i++) {
		cout << "input[" << i << "] = ." << inputs.at(i)->input << "." << endl;
	}
	return 0;
}
