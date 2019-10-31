# CS 100 Programming Project
# Fall Quarter 2019 Andrew Nguyen 862116434, Matthew Lee 862113311

# Intro:
Our program will be able to function as a basic shell that will be able to take in inputs that classify as executables, arguments, and/or connectors. We will be using a composite pattern to implement our shell so that we can add new functions to our program without risk of introducing bugs within a working system. The general format of how our inputs will be “ingested” with the cin function within the STL library <iostream> will be processed in a general format of: <dir name>$ <executable> [possible argument] [possible connector]. These inputs will be transformed into classes and structures with an interface through the use of inheritance, polymorphism, and encapsulation.

# Diagram
![OMT Diagram](https://github.com/cs100/assignment-scootscoot/master/images/OMT_Diagram_Prototype.JPG)


# Classes
* Input: This is our base class, which will help build up the composite class and Leaf children. 
* Inputs: This is our composite class which inherits from Input, which holds references to a collection of Input *, to StratExe *,  to StratCon *.
* Executable / Argument / Connector: These are our Leaf child which inherit from Input. They will be used in the collection of Input in the composite class to run differently, varying if they are an Executable, Argument, or a Connector.
* StratExe / StratCon: This is our strategy pattern, which will help us run different executables and connectors depending on Inputs.
* ls / echo / mkdir / Semicolon / Ampersand / Parallel: These will run individual functions that perform their executable/connector action.


# Prototypes
* Parser
  *We used getline (cin, str) to get the inputs from the user. Once we have the inputs from the user, we separate each command into either an executable, argument, or connector and add it to the vector<Input *>.
* Function Testing
  * With the fork() function, we can use our executables to run with our connectors so that the connectors function properly by having the fork() function run in a child and be able to move onto the next state, depending on the connector value.  
  * With the waitpid() function, we can stop “zombie” child being made by terminating any leftover child processes made by the fork() function. 
  * With the execvp() function, we will be able to run our executables with their arguments. 
* Connector Logic
  * For the semicolon, regardless if the first command works or not, it will move to the second command.
  * For the ampersands, if the first command works, it will move onto the second command. If the first command does not work, it will not move onto the second command.
  * For the parallel signs, if the first command works, it will not move onto the second command. If the first command does not work, it will move onto the second command.


# Dev Testing Roadmap
* InputData Class
  * Exectubale / Argument / Connector Class
  * Testing
* InputFunction Class
  * Testing
* Strategies
  * StratExe Class
    * ls / echo / mkdir Class
   * Testing
  * StratCon Class
    * Semicolon / Ampersand / Parallel Class
  * Testing
* Testing overall
* Turn in

