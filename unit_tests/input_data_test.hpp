#ifndef __INPUT_DATA_TEST_HPP__
#define __INPUT_DATA_TEST_HPP__

#include "../header/input_data.hpp"
#include "../header/input.hpp"
#include "gtest/gtest.h"

TEST(Parser, SimpleEcho) {
	string str = "echo ello";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0), "echo ello");
}


TEST(Parser, EchoSemiEcho) {
	string str = "echo ello; echo chap";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "echo ello");
	EXPECT_EQ(test.inputs.at(1), "; ");
	EXPECT_EQ(test.inputs.at(2), "echo chap");
}


TEST(Parser, EchoAndEcho) {
	string str = "echo ello && echo chap";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "echo ello ");
	EXPECT_EQ(test.inputs.at(1), "&&");
	EXPECT_EQ(test.inputs.at(2), "echo chap");
}


TEST(Parser, SimpleLs) {
	string str = "ls";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0), "ls");
}


TEST(Parser, LsSemiLs) {
	string str = "ls -a; ls";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "ls -a");
	EXPECT_EQ(test.inputs.at(1), "; ");
	EXPECT_EQ(test.inputs.at(2), "ls");
}


TEST(Parser, LsAndLs) {
	string str = "ls -a && ls";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "ls -a ");
	EXPECT_EQ(test.inputs.at(1), "&&");
	EXPECT_EQ(test.inputs.at(2), "ls");
}

TEST(Parser, LsSemiEchoAndEchoOrEchoSemiEchoSemiEchoQuote){
	string str = "ls -a; echo burt && echo bees || ooga booga; hur dur; echo \"hello world\"";
	InputData test(str);
	
	ASSERT_EQ(test.inputs.size(), 11);
	EXPECT_EQ(test.inputs.at(0), "ls -a");
	EXPECT_EQ(test.inputs.at(1), "; ");
	EXPECT_EQ(test.inputs.at(2), "echo burt ");
	EXPECT_EQ(test.inputs.at(3), "&&");
	EXPECT_EQ(test.inputs.at(4), "echo bees ");
	EXPECT_EQ(test.inputs.at(5), "||");
	EXPECT_EQ(test.inputs.at(6), "ooga booga");
	EXPECT_EQ(test.inputs.at(7), "; ");
	EXPECT_EQ(test.inputs.at(8), "hur dur");
	EXPECT_EQ(test.inputs.at(9), "; ");
	EXPECT_EQ(test.inputs.at(10), "echo \"hello world\"");
	
	
}

TEST(Parser, EchoOrLsComNoSpace) {
	string str = "echo \"wsup bro\" || ls#aweofijawefjadf";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "echo \"wsup bro\" ");
	EXPECT_EQ(test.inputs.at(1), "||");
	EXPECT_EQ(test.inputs.at(2), "ls ");
}

TEST(Parser, EchoOrLsComSpace) {
	string str = "echo \"wsup bro\" || ls -a #aweofijawefjadf";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "echo \"wsup bro\" ");
	EXPECT_EQ(test.inputs.at(1), "||");
	EXPECT_EQ(test.inputs.at(2), "ls -a");
}

TEST(Parser, TwoQuotes) {
	string str = "echo \"burts bees\"; echo \"ooga booga\"";
	InputData test(str);
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0), "echo \"burts bees\"");
	EXPECT_EQ(test.inputs.at(1), "; ");
	EXPECT_EQ(test.inputs.at(2), "echo \"ooga booga\"");
}
#endif
