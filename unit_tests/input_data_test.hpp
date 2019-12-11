#ifndef __INPUT_DATA_TEST_HPP__
#define __INPUT_DATA_TEST_HPP__

#include "../header/input_data.hpp"
#include "../header/input.hpp"
#include "../header/executable.hpp"
#include "../header/connector.hpp"
#include "gtest/gtest.h"

TEST(Parser, SimpleEcho) {
	string str = "echo ello";
	InputData test(str);
	test.takeInput();
	EXPECT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "echo ello");
}


TEST(Parser, EchoSemiEcho) {
	string str = "echo ello; echo chap";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "echo ello");
	EXPECT_EQ(test.inputs.at(1)->input, ";");
	EXPECT_EQ(test.inputs.at(2)->input, "echo chap");
}


TEST(Parser, EchoAndEcho) {
	string str = "echo ello && echo chap";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "echo ello");
	EXPECT_EQ(test.inputs.at(1)->input, "&&");
	EXPECT_EQ(test.inputs.at(2)->input, "echo chap");
}


TEST(Parser, SimpleLs) {
	string str = "ls";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "ls");
}


TEST(Parser, LsSemiLs) {
	string str = "ls -a; ls";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "ls -a");
	EXPECT_EQ(test.inputs.at(1)->input, ";");
	EXPECT_EQ(test.inputs.at(2)->input, "ls");
}


TEST(Parser, LsAndLs) {
	string str = "ls -a && ls";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "ls -a");
	EXPECT_EQ(test.inputs.at(1)->input, "&&");
	EXPECT_EQ(test.inputs.at(2)->input, "ls");
}

TEST(Parser, LsSemiEchoAndEchoOrEchoSemiEchoSemiEchoQuote){
	string str = "ls -a; echo burt && echo bees || ooga booga; hur dur; echo \"hello world\"";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 11);
	EXPECT_EQ(test.inputs.at(0)->input, "ls -a");
	EXPECT_EQ(test.inputs.at(1)->input, ";");
	EXPECT_EQ(test.inputs.at(2)->input, "echo burt");
	EXPECT_EQ(test.inputs.at(3)->input, "&&");
	EXPECT_EQ(test.inputs.at(4)->input, "echo bees");
	EXPECT_EQ(test.inputs.at(5)->input, "||");
	EXPECT_EQ(test.inputs.at(6)->input, "ooga booga");
	EXPECT_EQ(test.inputs.at(7)->input, ";");
	EXPECT_EQ(test.inputs.at(8)->input, "hur dur");
	EXPECT_EQ(test.inputs.at(9)->input, ";");
	EXPECT_EQ(test.inputs.at(10)->input, "echo \"hello world\"");
	
	
}

TEST(Parser, EchoOrLsComNoSpace) {
	string str = "echo \"wsup bro\" || ls#aweofijawefjadf";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "echo \"wsup bro\"");
	EXPECT_EQ(test.inputs.at(1)->input, "||");
	EXPECT_EQ(test.inputs.at(2)->input, "ls");
}

TEST(Parser, EchoOrLsComSpace) {
	string str = "echo \"wsup bro\" || ls -a #aweofijawefjadf";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "echo \"wsup bro\"");
	EXPECT_EQ(test.inputs.at(1)->input, "||");
	EXPECT_EQ(test.inputs.at(2)->input, "ls -a");
}

TEST(Parser, TwoQuotes) {
	string str = "echo \"burts bees\"; echo \"ooga booga\"";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 3);
	EXPECT_EQ(test.inputs.at(0)->input, "echo \"burts bees\"");
	EXPECT_EQ(test.inputs.at(1)->input, ";");
	EXPECT_EQ(test.inputs.at(2)->input, "echo \"ooga booga\"");
}

TEST(Parser, Parentheses) {
	string str = "(echo A && echo B)";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "(echo A && echo B)");
}

TEST(Parser, DoubleParentheses) {
	string str = "((echo A && echo B) && echo C)";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "((echo A && echo B) && echo C)");
}

TEST(Parser, Test_Command) {
	string str = "test -e header";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "test -e header");
}


TEST(Parser, SquareBracket) {
	string str = "[ -e header ]";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "-e header");
}

TEST(Parser, SingleAngleBracket) {
	string str = "cat < inputFile";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 1);
	EXPECT_EQ(test.inputs.at(0)->input, "cat < inputFile");
}

TEST(Parser, AngleBracketWithTrPipes) {
	string str = "cat < inputFile | tr A-Z a-z | tr A-Z a-z | tr A-Z a-z | tr A-Z a-z";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 9);
	EXPECT_EQ(test.inputs.at(0)->input, "cat < inputFile");
	EXPECT_EQ(test.inputs.at(1)->input, "|");
	EXPECT_EQ(test.inputs.at(2)->input, "tr A-Z a-z");
	EXPECT_EQ(test.inputs.at(3)->input, "|");
	EXPECT_EQ(test.inputs.at(4)->input, "tr A-Z a-z");
	EXPECT_EQ(test.inputs.at(5)->input, "|");
	EXPECT_EQ(test.inputs.at(6)->input, "tr A-Z a-z");
	EXPECT_EQ(test.inputs.at(7)->input, "|");
	EXPECT_EQ(test.inputs.at(8)->input, "tr A-Z a-z");
}

TEST(Parser, AngleBracketWithTeePipes) {
	string str = "cat < inputFile | tee outputFile1 | tee outputFile2 | tee outputFile3";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 7);
	EXPECT_EQ(test.inputs.at(0)->input, "cat < inputFile");
	EXPECT_EQ(test.inputs.at(1)->input, "|");
	EXPECT_EQ(test.inputs.at(2)->input, "tee outputFile1");
	EXPECT_EQ(test.inputs.at(3)->input, "|");
	EXPECT_EQ(test.inputs.at(4)->input, "tee outputFile2");
	EXPECT_EQ(test.inputs.at(5)->input, "|");
	EXPECT_EQ(test.inputs.at(6)->input, "tee outputFile3");

}

TEST(Parser, AngleBracketExample) {
	string str = "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 7);
	EXPECT_EQ(test.inputs.at(0)->input, "cat < existingInputFile");
	EXPECT_EQ(test.inputs.at(1)->input, "|");
	EXPECT_EQ(test.inputs.at(2)->input, "tr A-Z a-z");
	EXPECT_EQ(test.inputs.at(3)->input, "|");
	EXPECT_EQ(test.inputs.at(4)->input, "tee newOutputFile1");
	EXPECT_EQ(test.inputs.at(5)->input, "|");
	EXPECT_EQ(test.inputs.at(6)->input, "tr a-z A-Z > newOutputFile2");
}

TEST(Parser, AngleBracketExampleAndEcho) {
	string str = "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2 && echo hi";
	InputData test(str);
	test.takeInput();
	ASSERT_EQ(test.inputs.size(), 7);
	EXPECT_EQ(test.inputs.at(0)->input, "cat < existingInputFile");
	EXPECT_EQ(test.inputs.at(1)->input, "|");
	EXPECT_EQ(test.inputs.at(2)->input, "tr A-Z a-z");
	EXPECT_EQ(test.inputs.at(3)->input, "|");
	EXPECT_EQ(test.inputs.at(4)->input, "tee newOutputFile1");
	EXPECT_EQ(test.inputs.at(5)->input, "|");
	EXPECT_EQ(test.inputs.at(6)->input, "tr a-z A-Z > newOutputFile2");
	EXPECT_EQ(test.inputs.at(7)->input, "&&");
	EXPECT_EQ(test.inputs.at(8)->input, "echo hi");
}
















#endif
