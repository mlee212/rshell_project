CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
	unit_tests/unit_test.cpp
	src/executable.cpp
	src/input_data.cpp
	src/connector.cpp
	src/input.cpp
	src/parenthesis.cpp
	src/test_command.cpp
	src/square.cpp
	src/parallel.cpp
	src/ampersand.cpp
	src/semicolon.cpp
)

#ADD_EXECUTABLE(main
#	unit_tests/main.cpp
#	src/executable.cpp
#	src/input.cpp
#	src/test_command.cpp
#	src/square.cpp
#)

ADD_EXECUTABLE(manT
	unit_tests/main2.cpp
	src/input_data.cpp
	src/input.cpp
	src/executable.cpp
	src/connector.cpp
	src/parenthesis.cpp
	src/test_command.cpp
	src/square.cpp
	src/parallel.cpp
	src/ampersand.cpp
	src/semicolon.cpp
#unit_test.cpp
)

ADD_EXECUTABLE(rshell
	unit_tests/rshell.cpp
	src/input_data.cpp
	src/input.cpp
	src/executable.cpp
	src/connector.cpp
	src/parenthesis.cpp
	src/test_command.cpp
	src/square.cpp
	src/parallel.cpp
	src/ampersand.cpp
	src/semicolon.cpp
)

#ADD_EXECUTABLE(test2
	#unit_tests/unit_test.cpp
	#src/input_data.cpp
	#vector_container.cpp
	#selection_sort.cpp
	#list_container.cpp
	#bubble_sort.cpp
#)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
