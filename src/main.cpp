#include <iostream>
#include <gtest/gtest.h>
#include "HouseOwner.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
  
    std::cout << "Hello, from sb!\n";
    HouseOwner owner1("ahmed", 25, "ahmed@ex.com");
    owner1.browseTypes();
    owner1.installSB();
    
    return RUN_ALL_TESTS();
}

