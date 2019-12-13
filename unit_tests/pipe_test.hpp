#ifndef __PIPE_TEST_HPP__
#define __PIPE_TEST_HPP__

#include "../header/input_data.hpp"
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "../header/pipe.hpp"
#include "gtest/gtest.h"

//TEST(Pipe, SingleArg) {
//	InputData x("echo hi | tr a-z A-Z");
//	x.takeInput();
//	EXPECT_EQ(x.run(), 1);
//}
//TEST(Pipe, MultiArg) {
//	InputData x("echo hi | tr a-z A-Z | tr A-Z a-z");
//	x.takeInput();
//	EXPECT_EQ(x.run(), 1);
//}
TEST(Pipe, Example) {
	InputData x("cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
}
//TEST(Pipe, Error1) {
//	InputData x("echo hi | | && | tr a-z A-Z");
//	x.takeInput();
//	EXPECT_EQ(x.run(), -1);
//}
TEST(Pipe, Error2) {
	InputData x("echo hi tr a-z | A-Z");
	x.takeInput();
	EXPECT_EQ(x.run(), -1);
}

#endif
