#ifndef __EXECUTABLE_TEST_HPP__
#define __EXECUTABLE_TEST_HPP__

#include "../header/executable.hpp"
#include "gtest/gtest.h"

TEST(ExecutableTest, TestLS){
	Input * x = new Executable("ls");
	
	EXPECT_EQ(x->run(), 0);
	
}

TEST(ExecutableTest, TestEcho) {
	Input * x = new Executable("echo");
	
	EXPECT_EQ(x->run(), 0);
}

TEST(ExecutableTest, Error) {
	Input * x = new Executable("unicorn");

	EXPECT_EQ(x->run(), -1);
}

#endif
