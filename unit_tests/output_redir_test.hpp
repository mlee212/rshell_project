#ifndef __OUTPUT_REDIR_TEST_HPP__
#define __OUTPUT_REDIR_TEST_HPP__

#include "../header/input_data.hpp"
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "gtest/gtest.h"

TEST(OutputRedir, SingleArg) {
	InputData x("cat < singleArgFile.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
	
}
//TEST(OutputRedir, MultiArg) {
//	InputData x("cat < multiArgFile1.txt && cat < multiArgFile2.txt && cat < multiArgFile3.txt");
//	x.takeInput();
//	EXPECT_EQ(x.run(), 1);
	
//}
TEST(OutputRedir, Error1) {
	InputData x("cat < singleArgFile.txt derp");
	x.takeInput();
	EXPECT_EQ(x.run(), -1);
}
//TEST(OutputRedir, Error2) {
//	InputData x("so cat < singleArgFile.txt");
//	x.takeInput();
//	EXPECT_EQ(x.run(), -1);
//}
TEST(OutputRedir, ErrorNonExist) {
	InputData x("cat < awerfsdlkjq.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), -1);
}

#endif

