CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
	~/assignment-scootscoot/unit_tests/unit_test.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/input_data.cpp
	~/assignment-scootscoot/src/connector.cpp
	~/assignment-scootscoot/src/input.cpp
)

ADD_EXECUTABLE(main
	~/assignment-scootscoot/unit_tests/main.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/input.cpp
)

ADD_EXECUTABLE(manT
	~/assignment-scootscoot/unit_tests/main2.cpp
	~/assignment-scootscoot/src/input_data.cpp
	~/assignment-scootscoot/src/input.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/connector.cpp
	#unit_test.cpp
)

ADD_EXECUTABLE(rshell
	~/assignment-scootscoot/unit_tests/rshell.cpp
	~/assignment-scootscoot/src/input_data.cpp
	~/assignment-scootscoot/src/input.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/connector.cpp
)

#ADD_EXECUTABLE(test2
#	~/assignment-scootscoot/unit_tests/unit_test.cpp
#	~/assignment-scootscoot/src/input_data.cpp
	#vector_container.cpp
	#selection_sort.cpp
	#list_container.cpp
	#bubble_sort.cpp
#)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
