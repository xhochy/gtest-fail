#include "gtest/gtest.h"

int two() {
  return 2;
}

TEST(SomeTest, Here) {
  EXPECT_EQ(1, two());
  ASSERT_EQ(1, two());
}
