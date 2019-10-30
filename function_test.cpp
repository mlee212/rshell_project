#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char * argv[]){
	pid_t pid = fork();
	char * args[] = {"ls", NULL};
	int status;
	if (pid < 0){
		std::cout << "Failed to fork" << std::endl;
		return 0;
	}
	else if (pid > 0){
		std::cout << "Parent process: " << getpid() << std::endl;
		waitpid(0, &status , WNOHANG);
	}
	else {
		std::cout << "Child process: " << getpid() << std::endl;
		if (execvp(args[0], args) < 0){
			std::cout << "Failed to execute" << std::endl;
			return 0;
		}
	}
	
	return 0;
}
