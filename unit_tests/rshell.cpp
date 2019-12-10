#include "../header/input_data.hpp"

int main(int argc, char ** argv){
	//string x;
	//cout << "argc: " << argc << endl;
	//for (int i = 1; i < argc; i++){
	//	if (i != argc - 1){
	//		x = x + argv[i] + ' ';
	//	}
	//	else {
	//		x = x + argv[i];
	//	}
		//cout << "argv[ " << i << "]: " << argv[i] << endl;
	//}
	//cout << "x: " << x << endl;
	//InputData test(x);
	//test.takeInput();
	//test.run();

	string x;
	cout << "$ ";
	getline(cin, x);
	InputData test(x);
	test.takeInput();
	test.run();
	

	return 0;
}
