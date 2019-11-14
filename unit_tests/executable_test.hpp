#ifndef __EXECUTABLE_TEST_HPP__
#define __EXECUTABLE_TEST_HPP__

#include "../header/executable.hpp"
#include "gtest/gtest.h"

TEST(ExecutableTest, TestLS){
	Input * x = new Executable("ls");
	//EXPECT_EQ(ls, x->run());
}


#endif
