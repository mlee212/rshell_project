#include "../header/input_data.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "../header/input.hpp"
#include "../header/parenthesis.hpp"
//#include "../header/ampersand.hpp"
//#include "../header/parallel.hpp"
//#include "../header/semicolon.hpp"



void InputData::takeInput() {
//	string str;
//	cout << "$";
//	getline(cin, str);
	
	while (str.at(0) == '(' && str.at(str.length() - 1) == ')') {
		str = str.substr(1, str.length() - 2);
	}
	
	bool quote = false;
	//cout << "og str:" << str << endl;
	for(int i = 0; i < str.size(); i++) {
	//	if(str.at(i) == '\"' && !quote){
	//		quote = true;
	//		str.insert(i, " ");
	//		i++;
	//		str.insert(i + 1, " ");
	//		i++;
	//	}
	//	if(str.at(i) == '\"' && quote) {
	//		quote = false;
	//		str.insert(i, " ");
	//		i++;
	//		str.insert(i + 1, " ");
	//		i++;
	//	}
		if(str.at(i) == '\"') {
			quote = !quote;
		}
		if (str.at(i) == ';' && !quote) {
			str.insert(i," ");
			i++;
		}
		if (str.at(i) == '#' && i != 0 && !quote) {
			str.insert(i, " ");
			i++;
			str.insert(i + 1, " ");
			i++;
		}
			
	}
	string quoteStr = str;
	
	//cout << "first mod str:" << str << endl;

	
	int indexS = 0;
	int indexE = 0;
	int exeLength = 0;
	string temp;
	quote = false;
	int paren = 0;
	bool quoteSec = false;
	bool quit = false;
	bool quitCheck = false;
	bool start = true;
	string quitStr;


	//indexE++;
	//cout << str << endl;
	stringstream ss(str);
	while(ss >> temp) {
		
		for(int i = 0; i < temp.size(); i++) {
			if (temp.at(i) == '\"') {
				quote = !quote;
			}
			if(temp.at(i) == '(' && !quote) {
				paren++;
			}
			if(temp.at(i) == ')' && !quote) {
				paren--;
			}
		}
		if(quote){
		//	quote = true;
		//	quoteSec = false;
			for(int i = 0; i < temp.size(); i++) {
				indexE++;
				exeLength++;
			//	if(temp.at(i) == '#') {
			//		quit = true;
			//		break;
			//	}
		//		if(temp.at(i) == '\"') {
		//			quote = !quote;
		//		}
			
			}
		//	if(temp.at(temp.size() - 1) = '\"') {
		//		quoteSec = true;
		//	} 
			//if(quit) {
			//	for(int i = 0; i < temp.size(); i++) {
			//		if(temp.at(i) == '#') {
			//			quitCheck = true;
			//		}
			//		if(!quitCheck) {
			//			quitStr += temp.at(i);
			//		}
			//	}
			//	temp = quitStr;
			//}
			indexE += 1;
			exeLength += 1;
		}
		else if(paren > 0){
		//	quote = true;
		//	quoteSec = false;
			cout << "Paren length: " << paren << endl;
			if(start) {
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				}
			}
			else {
				for(int i = 0; i < temp.size(); i++) {
					indexE++;
					exeLength++;
				//	if(temp.at(i) == '#') {
				//		quit = true;
				//		break;
				//	}
			//		if(temp.at(i) == '\"') {
			//			quote = !quote;
			//		}
				
				}
			//	if(temp.at(temp.size() - 1) = '\"') {
			//		quoteSec = true;
			//	} 
				//if(quit) {
				//	for(int i = 0; i < temp.size(); i++) {
				//		if(temp.at(i) == '#') {
				//			quitCheck = true;
				//		}
				//		if(!quitCheck) {
				//			quitStr += temp.at(i);
				//		}
				//	}
				//	temp = quitStr;
				//}
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
			//	if(temp.at(i) == '\"') {
			//		quote = !quote;
			//	}
			
			}
			// if(quit) {
			//	for(int i = 0; i < temp.size(); i++) {
			//		if(temp.at(i) == '#') {
			//			quitCheck = true;
			//		}
			//		if(!quitCheck) {
			//			quitStr += temp.at(i);
			//		}
			//	}
			//	temp = quitStr;
			//}
			if((temp == "&&")  && !quote) {
				//cout << "Exe + args: " << str.substr(indexS, exeLength) << endl;
				
				if(str.at(indexS) == '(') {
					inputs.push_back(new Parenthesis(str.substr(indexS, --exeLength)));
				}
				else {
					inputs.push_back(new Executable(str.substr(indexS, --exeLength)));
				}
				//cout << "connector: " << str.substr(indexE, temp.size()) << endl;
				//cout << indexE << endl;
				inputs.push_back(new Connector(str.substr(indexE, temp.size())));
				//indexS = indexE + temp.size() + 1;
				//indexE = indexS
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
			}
			else if(temp == "||" && !quote) {
				//cout << "Exe + args: " << str.substr(indexS, exeLength) << endl;
				if(str.at(indexS) == '(') {
					inputs.push_back(new Parenthesis(str.substr(indexS, --exeLength)));
				}
				else {
					inputs.push_back(new Executable(str.substr(indexS, --exeLength)));
				}
				//cout << "connector: " << str.substr(indexE, temp.size()) << endl;
				//cout << indexE << endl;
				inputs.push_back(new Connector(str.substr(indexE, temp.size())));
				//indexS = indexE + temp.size() + 1;
				//indexE = indexS
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
				
				
			}
			else if(temp == ";"  && !quote ) {
				if(str.at(indexS) == '(') {
					inputs.push_back(new Parenthesis(str.substr(indexS, exeLength)));
				}
				else {
					inputs.push_back(new Executable(str.substr(indexS, exeLength)));
				}
				inputs.push_back(new Connector(str.substr(indexE + 1, temp.size() /* + 1 */)));
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
			}
			else if(temp == "#"  && !quote ) {
				if(str.at(indexS) == '(') {
					inputs.push_back(new Parenthesis (str.substr(indexS, exeLength)));
				}
				else {
					inputs.push_back(new Executable (str.substr(indexS, exeLength)));
				}
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
				quitCheck = true;
			}
			//if(singular) {
			//	inputs.push_back(str);
			//}
			//if(quote && quoteSec) {
			//	quote = false;
			//	quoteSec = false;
			//	quoteStr += str.substr(indexS + 1, exeLength);
			//	inputs.push_back(new Executable(quoteStr));
			//	exeLength = 0;
			//	indexS = indexE + 2;
			//	indexE = indexS;
			//}
			//else if (quote) {
			//	if (quote && !quoteSec) {
			//		quoteStr = str.substr(indexS, exeLength);
			//		cout << "first part: " << str.substr(indexS, exeLength);
			//		indexS = indexE;
			//	}
			//	quoteSec = true;
			//}
		}
	}
	
	if (quitCheck) {
		//cout << "quitStr: "<< quitStr.size() << endl;
		//inputs.push_back(new Executable(str.substr(indexS, quitStr.size() + 3)));

	}
	else {
		//cout << "what is this: " << str.substr(indexS, indexE + 2) << endl;
		
		inputs.push_back(new Executable(str.substr(indexS, indexE + 2)));
	}
	//cout << "Exe + args: " << str.substr(indexS, indexE) << endl;
	// -------------- TEST -----------------------
	//cout << "hello" << endl;
	//cout << indexE << endl;
	//cout << str.size() - 1<< endl;	
	for(int i = 0; i < inputs.size(); i++) {
		cout << inputs.at(i)->input << endl;
		while(inputs.at(i)->input.at(0) == '(' && inputs.at(i)->input.at(inputs.at(i)->input.length() - 1) == ')') {
			inputs.at(i)->input = inputs.at(i)->input.substr(1, inputs.at(i)->input.length() - 2);
		}
		cout << "After: " << inputs.at(i)->input << endl;
		
	}
	cout << "size: " << inputs.size() << endl;
	//cout << "hello" << endl;
	cout << "inputs size: " << inputs.size() << endl;
//	cout << inputs.at(0) << endl << inputs.at(1) << endl;
	//cout << "hello 2" << endl;
	
}

int InputData::run() {
	bool next = true;
	int stat;
	pid_t pid[inputs.size()];
	for (int i = 0; i < inputs.size(); i++)	{
		//cout << i << endl;
		if (i % 2 == 1){
			if ((pid[i] = fork()) == 0){
				//cout << "This is child: " << getpid() << endl;
				if (inputs.at(i - 1)->run() == -1){
					exit(2);
				}
				exit(1);
			}
			else {
				//cout << "This is parent: " << i << endl;
				pid_t test = waitpid(pid[i], &stat, 0);
				if (i != inputs.size() - 1){
					if (WIFEXITED(stat)){
						//cout << "Child: " << test << " / terminated: " << WEXITSTATUS(stat) << endl;
						if (inputs.at(i)->input == "&&" || inputs.at(i)->input == "&& "){
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
							if (WEXITSTATUS(stat) == 0){
								cout << "Skip ||" << endl;
								next = false;
								i += 2;
							}
							else {
								next = true;
								cout << "Went next ||" << endl;
							}
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
		inputs.at(inputs.size() - 1)->run();
	}
	if (inputs.size() == 1){
		inputs.at(0)->run();
	}
	return 0;
}

