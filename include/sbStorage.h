#pragma once
#include <iostream>
#include <memory>
#include "Network.h"

enum MODE{
    CHARGING,
    DISCHARING
};

enum SETUP{
    BASIC,
    STANDARD,
    PRO
};

class sbStorage
{
private:
    int nb_inverters;
    int nb_modules;
    int nb_controllers;
    int production;
    int energyFromGrid;
    int energyToGrid;
    int consumption;
    int storage;
    int capacity;
    MODE charge_mode;
    std::unique_ptr<Network> network_ptr_;
public:
    sbStorage(std::unique_ptr<Network> network_ptr);
    ~sbStorage();
    void setup(SETUP s);
    void setChargeMode(int m);
    int getStorage();
    void energeAlgo();
    int getPowerToGrid();
    int getPowerFromGrid();
};

