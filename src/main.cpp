#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "HouseOwner.h"

struct OwnerParams {
    std::string name;
    int age;
    std::string email;
    int type;
    int housePower;
    int gridPower;
    int pvPower;
    int expectedCost;
    int expectedRevenue;
    bool shouldThrowError;
};

class HouseOwnerParameterizedTest : public testing::TestWithParam<OwnerParams> {
protected:
    void SetUp() override {
        const auto& params = GetParam();
        owner = std::make_unique<HouseOwner>(params.name, params.age, params.email);
    }

    std::unique_ptr<HouseOwner> owner;
};

TEST(HouseOwnerTest, SelectTypeThrowsInvalidArgument) {
    HouseOwner owner("ahmed", 30, "ahmed@ex.com");

    // Test with an invalid type to trigger the exception
    auto network_ptr = std::make_unique<Network>();
    EXPECT_THROW(owner.selectType(-1, std::move(network_ptr)), std::invalid_argument);
}

TEST_P(HouseOwnerParameterizedTest, PowerAndBrowseTypeTest) {
    const auto& params = GetParam();
    auto network_ptr = std::make_unique<Network>();
    network_ptr->updatePower(params.housePower, params.gridPower, params.pvPower);
    owner->selectType(params.type, std::move(network_ptr));

    EXPECT_EQ(owner->getCost(), params.expectedCost);
    EXPECT_EQ(owner->getRevenue(), params.expectedRevenue);
}

INSTANTIATE_TEST_SUITE_P(
    OwnerTests,
    HouseOwnerParameterizedTest,
    testing::Values(
        //OwnerParams{name, age, email, setup, housePower, gridPower, pvPower, cost, revenue}
        OwnerParams{"ahmed", 25, "ahmed@ex.com", 0, 50, 1000, 20, 300, 0, false},
        OwnerParams{"sara", 30, "sara@ex.com", 1, 100, 1000, 40, 600, 0, false},
        OwnerParams{"john", 35, "john@ex.com", 2, 200, 1000, 50, 1500, 0, false},
        OwnerParams{"ahmed", 25, "ahmed@ex.com", 0, 20, 1000, 60, 0, 200, false},
        OwnerParams{"sara", 30, "sara@ex.com", 1, 40, 1000, 100, 0, 300, false},
        OwnerParams{"john", 35, "john@ex.com", 2, 50, 1000, 150, 0, 500, false}
    )
);


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
  
    std::cout << "Hello, from sb!\n";
    
    ///return 0;
    return RUN_ALL_TESTS();
}

