#pragma once
#include <iostream>
#include <memory>
#include "sbStorage.h"

class installation
{
private:
    /* data */
    int houseId;
    int totalCost;
    int revenue;
    SETUP sb_setup;
    int installationDate;
    std::unique_ptr<sbStorage> sb_ptr;
public:
    installation(int id, int selected_setup, std::unique_ptr<Network> network_ptr);
    int calcCost(int id);
    int calcRevenue(int id);
    void printDetails();
    ~installation();
};
