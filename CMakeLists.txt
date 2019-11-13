CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	~/assignment-scootscoot/unit_tests/unit_test.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/input.cpp
)

ADD_EXECUTABLE(main
	~/assignment-scootscoot/unit_tests/main.cpp
	~/assignment-scootscoot/src/executable.cpp
	~/assignment-scootscoot/src/input.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
