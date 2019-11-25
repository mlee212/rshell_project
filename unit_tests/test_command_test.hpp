#ifndef __TEST_COMMAND_TEST_HPP__
#define __TEST_COMMAND_TEST_HPP__

#include "../header/test_command.hpp"
#include "gtest/gtest.h"

TEST(TestCommandTest, Test_E_File){
	Input * x = new TestCommand("test -e rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(TestCommandTest, Test_F_File){
	Input * x = new TestCommand("test -f rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(TestCommandTest, Test_D_File){
	Input * x = new TestCommand("test -d rshell");
	EXPECT_EQ(x->run(), -1);
}

TEST(TestCommandTest, Test_Nothing_File){
	Input * x = new TestCommand("test rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(TestCommandTest, Test_D_Dir){
	Input * x = new TestCommand("test -d header");
	EXPECT_EQ(x->run(), 1);
}

TEST(TestCommandTest, Test_F_Dir){
	Input * x = new TestCommand("test -f header");
	EXPECT_EQ(x->run(), -1);
}

TEST(TestCommandTest, Test_Nothing_Dir){
	Input * x = new TestCommand("test header");
	EXPECT_EQ(x->run(), 1);
}

TEST(TestCommandTest, Test_E_Mispell){
	Input * x = new TestCommand("test -e u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}

TEST(TestCommandTest, Test_F_Mispell){
	Input * x = new TestCommand("test -f u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}

TEST(TestCommandTest, Test_D_Mispell){
	Input * x = new TestCommand("test -e hea");
	EXPECT_EQ(x->run(), -1);
}

TEST(TestCommandTest, Test_Nothing_Mispell){
	Input * x = new TestCommand("test u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}




#endif
