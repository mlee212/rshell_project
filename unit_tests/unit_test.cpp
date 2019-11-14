#include "gtest/gtest.h"
#include "input_data_test.hpp"
#include "executable_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
