#include <gtest/gtest.h>

/// testing data
// Turtle yellow("yellow");
// cout << yellow;
// Command mvmnt = {CommandType::forward, 10};
// Command mvmnt2 = {CommandType::down, 5};
// Command mvmnt3 = {CommandType::forward, 8};
// Command mvmnt4 = {CommandType::up, 3};

// yellow.move(mvmnt);
// cout << yellow;
// yellow.move(mvmnt2);
// yellow.move(mvmnt3);
// cout << yellow;
// yellow.move(mvmnt4);
// cout << yellow;

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
