# CS 100 Programming Project
# Fall Quarter 2019 Andrew Nguyen 862116434, Matthew Lee 862113311

# Intro:
Our program will be able to function as a basic shell that will be able to take in inputs that classify as executables, arguments, and/or connectors. We will be using a composite pattern to implement our shell so that we can add new functions to our program without risk of introducing bugs within a working system. The general format of how our inputs will be “ingested” with the cin function within the STL library <iostream> will be processed in a general format of: <dir name>$ <executable> [executable] [possible connector]. These inputs will be transformed into classes and structures with an interface through the use of inheritance, polymorphism, and encapsulation.

# Diagram
![OMT Diagram](https://github.com/cs100/assignment-scootscoot/blob/master/images/Second%20OMT%20Diagram.JPG)


# Classes
* Input: This is our base class, which will be the base class that holds a virtual run function of type int to indicate the status of executed functions. 
* InputData: This is our composite class which inherits from Input. The InputData class will take in an input, parse it into a vector of Input pointers.
* Executable: This class will inherit from the Input base class and will construct an Executable object that holds the string to be executed. The run function in this class will execute the command held within the string and return a negative number if the process failed.
* Connector: This class will inherit from the Input base class and will construct a Connector object that holds the string of the connector that will be used to determine whether or not the next Executable object should be executed. The run function will determine its identity as a Connector.

# Prototypes
* Parser: We used getline (cin, str) to get the inputs from the user. Once we have the inputs from the user, we separate each command into either an executable, argument, or connector and add it to the vector<Input *>.
* Function Testing
  * With the fork() function, we can use our executables to run with our connectors so that the connectors function properly by having the fork() function run in a child and be able to move onto the next state, depending on the connector value.
  * With the waitpid() function, we can stop “zombie” child being made by terminating any leftover child processes made by the fork() function.
  * With the execvp() function, we will be able to run our executables with their arguments.
* Connector Logic
  * For the semicolon, regardless if the first command works or not, it will move to the second command.
  * For the ampersands, if the first command works, it will move onto the second command. If the first command does not work, it will not move onto the second command.
  * For the parallel signs, if the first command works, it will not move onto the second command. If the first command does not work, it will move onto the second command.
* Post-Prototype
  * The Protoype's initial parser helped us realize that we could create a "partial parser" where the vector of inputs would contain strings of executables and arguments combined and connectors separately.
  * The function testing of fork(), waitpid(), and execvp() helped us run our inputs without ending the entire program.
  * The connector logic helped us understand how all of the inputs would run together.
  * The Prototype's design helped us realize that our initial design was too complex and unnecessarily complicated and guided us to implement something much more simple and streamlined.

# Dev Testing Roadmap
* Input Class
  * Created base class
* InputData Class
  * Worked on Parser
  * Unit Testing with Gtest
* Executable Class
  * Worked on making functional executable objects
  * Unit Testing with Gtest
* Connector Class
  * Created Connector Object to distinguish Executables and Connectors
* Rshell
  * Created rshell executable
  * Created integration tests
* Testing overall
* Turn in

