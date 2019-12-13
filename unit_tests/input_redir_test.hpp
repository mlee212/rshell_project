#ifndef __INPUT_REDIR_TEST_HPP__
#define __INPUT_REDIR_TEST_HPP__

#include "../header/input_data.hpp"
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "gtest/gtest.h"

TEST(InputRedir, SingleArg) {
	InputData x("echo hi > singleArgFile.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
	
}
TEST(InputRedir, MultiArg) {
	InputData x("echo hi > multiArgFile1.txt && echo hello > multiArgFile2.txt && echo \"hey wsup bro\" > multiArgFile3.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
	
}
//TEST(InputRedir, MultiFile) {
//	InputData x("echo hi > singleArgFile.txt derp");
//	x.takeInput();
//	EXPECT_EQ(x.run(), 1);
//}
//TEST(InputRedir, Error2) {
//	InputData x("so echo hi > singleArgFile.txt");
//	x.takeInput();
//	EXPECT_EQ(x.run(), -1);
//}
TEST(InputRedir, SingleArgConcat) {
	InputData x("echo hi >> singleArgFile.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
}
TEST(InputRedir, MultiArgConcat) {
	InputData x("echo hehehe >> multiArgFile1.txt && echo hehehe >> multiArgFile2.txt && echo hehehe >> multiArgFile3.txt");
	x.takeInput();
	EXPECT_EQ(x.run(), 1);
}
//TEST(InputRedir, ErrorConcat) {
//	InputData x("so echo hi > singleArgFile.txt");
//	x.takeInput();
//	EXPECT_EQ(x.run(), -1);
//}
#endif
