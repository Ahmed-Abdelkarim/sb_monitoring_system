#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "installation.h"

class HouseOwner
{
private:
    /* data */
    std::string name;
    int age;
    std::string email;
    int type;
    int houseId;
    std::unique_ptr<installation> install_ptr;
public:
    HouseOwner(/* args */);
    HouseOwner(std::string userName, int userAge, std::string useEmail);
    void selectType(int t, std::unique_ptr<Network> network_ptr);
    int getCost();
    int getRevenue();
    void printDetails();
};

