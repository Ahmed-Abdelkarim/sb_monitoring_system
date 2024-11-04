#pragma once
#include <string>
#include <iostream>
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
public:
    HouseOwner(/* args */);
    HouseOwner(std::string userName, int userAge, std::string useEmail);
    void browseTypes();
    void installSB();
    void printDetails();
    ~HouseOwner();
};

