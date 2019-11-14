CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(manT
	main.cpp
	input_data.cpp
	#unit_test.cpp
)

ADD_EXECUTABLE(test
	unit_test.cpp
	input_data.cpp
	#vector_container.cpp
	#selection_sort.cpp
	#list_container.cpp
	#bubble_sort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
