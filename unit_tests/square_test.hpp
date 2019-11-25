#ifndef __SQUARE_TEST_HPP__
#define __SQUARE_TEST_HPP__

#include "../header/square.hpp"
#include "gtest/gtest.h"

TEST(SquareTest, Square_E_File){
	Input * x = new Square("-e rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(SquareTest, Square_F_File){
	Input * x = new Square("-f rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(SquareTest, Square_D_File){
	Input * x = new Square("-d rshell");
	EXPECT_EQ(x->run(), -1);
}

TEST(SquareTest, Square_Nothing_File){
	Input * x = new Square("rshell");
	EXPECT_EQ(x->run(), 1);
}

TEST(SquareTest, Square_D_Dir){
	Input * x = new Square("-d header");
	EXPECT_EQ(x->run(), 1);
}

TEST(SquareTest, Square_F_Dir){
	Input * x = new Square("-f header");
	EXPECT_EQ(x->run(), -1);
}

TEST(SquareTest, Square_Nothing__Dir){
	Input * x = new Square("header");
	EXPECT_EQ(x->run(), 1);
}

TEST(SquareTest, Square_E__Mispell){
	Input * x = new TestCommand("-e u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}

TEST(SquareTest, Square_F_Mispell){
	Input * x = new Square("-f u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}

TEST(SquareTest, Square_D_Mispell){
	Input * x = new Square("-e hea");
	EXPECT_EQ(x->run(), -1);
}

TEST(SquareTest, Square_Nothing_Mispell){
	Input * x = new Square("u_test.cpp");
	EXPECT_EQ(x->run(), -1);
}




#endif
