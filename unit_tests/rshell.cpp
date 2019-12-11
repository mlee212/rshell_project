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

	//int save = dup(1);
	//int file = open("test5.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	//dup2(file, 1);
	//cout << "HELLLLLLLLO" << endl;
	//dup2(save, 1);

	for(; ;) {
		string x;
		cout << "$ ";
		getline(cin, x);
		InputData test(x);
		test.takeInput();
		test.run();
	}

	return 0;
}
