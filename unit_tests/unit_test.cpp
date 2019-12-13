#include "input_data_test.hpp"
#include "executable_test.hpp"
#include "test_command_test.hpp"
#include "square_test.hpp"
#include "input_redir_test.hpp"
#include "output_redir_test.hpp"
#include "pipe_test.hpp"

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
