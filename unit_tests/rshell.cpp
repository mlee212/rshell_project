#include "../header/input_data.hpp"

int main(int argc, char ** argv){
	string x;
	for (int i = 1; i < argc; i++){
		if (i != argc - 1){
			x = x + argv[i] + ' ';
		}
		else {
			x = x + argv[i];
		}
		cout << "argv[ " << i << "]: " << argv[i] << endl;
	}
	cout << "x: " << endl;
	InputData test(x);
	test.takeInput();
	test.run();

	return 0;
}
