#include <gtest/gtest.h>
#include "core/message.hpp"

TEST(MessageTest, ConstructAndPrint) {
    core::Message msg("Test");
    // Add test implementation
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
