#include "inputData.hpp"

InputData::InputData() {
	string str;
	cout << "$";
	getline(cin, str);
	bool quote = false;

	for(int i = 0; i < str.size(); i++) {
		//if(str.at(i) == '\"'){
		//	quote = !quote;
		//}
		if (str.at(i) == ';' && !quote) {
			str.insert(i," ");
			i++;
		}
			
	}
	
	int indexS = 0;
	int indexE = 0;
	int exeLength = 0;
	string temp;
	string quoteStr;
	quote = false;
	bool quoteSec = false;
	bool singular = true;
	
	//indexE++;
	//cout << str << endl;
	stringstream ss(str);
	while(ss >> temp) {
		if(temp.at(0) == '\"'){
			for(int i = 0; i < temp.size(); i++) {
				indexE++;
				exeLength++;
				//if(temp.at(i) == '\"') {
				//	quote = !quote;
				//}
			
			}
			indexE += 1;
			exeLength += 1;
		}
		else {
			for(int i = 0; i < temp.size(); i++) {
				indexE++;
				exeLength++;
				//if(temp.at(i) == '\"') {
				//	quote = !quote;
				//}
			
			}
			if((temp == "&&" || temp == "||") /* && !quote */) {
				//cout << "Exe + args: " << str.substr(indexS, exeLength) << endl;
				inputs.push_back(/* new Executable */(str.substr(indexS, exeLength)));
				
				//cout << "connector: " << str.substr(indexE, temp.size()) << endl;
				//cout << indexE << endl;
				inputs.push_back(str.substr(indexE, temp.size()));
				//indexS = indexE + temp.size() + 1;
				//indexE = indexS
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
				singular = false;
			}
			else if(temp == ";" /* && !quote */) {
				inputs.push_back(/* new Executable */(str.substr(indexS, exeLength)));
				inputs.push_back(str.substr(indexE + 1, temp.size() + 1));
				exeLength = 0;
				indexS = indexE + 3;
				indexE = indexS;
				singular = false;
			}
			//if(singular) {
			//	inputs.push_back(str);
			//}
//			if(quote && quoteSec) {
//				quote = false;
//				quoteSec = false;
//				quoteStr += str.substr(indexS + 1, exeLength);
//				inputs.push_back(quoteStr);
//				exeLength = 0;
//				indexS = indexE + 2;
//				indexE = indexS;
//			}
//			else if (quote) {
//				if (quote && !quoteSec) {
//					quoteStr = str.substr(indexS, exeLength);
//					cout << "first part: " << str.substr(indexS, exeLength);
//					indexS = indexE;
//				}
//				quoteSec = true;
//			}
		}
	}
	
	inputs.push_back(str.substr(indexS, indexE + 1));
	//cout << "Exe + args: " << str.substr(indexS, indexE) << endl;
	// -------------- TEST -----------------------
	//cout << "hello" << endl;
	cout << indexE << endl;
	cout << str.size() - 1<< endl;	
	for(int i = 0; i < inputs.size(); i++) {
		cout << inputs.at(i) << endl;
	}
	//cout << "hello 2" << endl;
	
}
