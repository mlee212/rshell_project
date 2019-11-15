# CS 100 Programming Project
# Fall Quarter 2019 Andrew Nguyen 862116434, Matthew Lee 862113311

# Intro:
Our program will be able to function as a basic shell that will be able to take in inputs that classify as executables, arguments, and/or connectors. We will be using a composite pattern to implement our shell so that we can add new functions to our program without risk of introducing bugs within a working system. The general format of how our inputs will be “ingested” with the cin function within the STL library <iostream> will be processed in a general format of: <dir name>$ <executable> [possible argument] [possible connector]. These inputs will be transformed into classes and structures with an interface through the use of inheritance, polymorphism, and encapsulation.

# Diagram
![OMT Diagram](https://github.com/cs100/assignment-scootscoot/blob/master/images/Second%20OMT%20Diagram.JPG)


# Classes
* Input: This is our base class, which will be the base class that holds a virtual run function of type int to indicate the status of executed functions. 
* InputData: This is our composite class which inherits from Input. The InputData class will take in an input, parse it into a vector of Input pointers.
* Executable: This class will inherit from the Input base class and will construct an Executable object that holds the string to be executed. The run function in this class will execute the command held within the string and return a negative number if the process failed.
* Connector: This class will inherit from the Input base class and will construct a Connector object that holds the string of the connector that will be used to determine whether or not the next Executable object should be executed. The run function will determine its identity as a Connector.

# Dev Testing Roadmap
* InputData Class
  * Worked on Parser
  * Unit Testing with Gtest
* Executable Class
  * Worked on making functional executable objects
  * Unit Testing with Gtest
* Rshell
  * Created rshell executable
  * Created integration tests
* Testing overall
* Turn in

