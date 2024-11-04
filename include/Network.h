#pragma once
#include <memory>
#include "HouseGrid.h"
#include "PV.h"
#include "Grid.h"

class Network
{
private:
    /* data */
public:
    std::shared_ptr<HouseGrid> hg_ptr;
    std::shared_ptr<Grid> g_ptr;
    std::shared_ptr<PV> pv_ptr;

    Network();
    void updatePower(int house_power, int grid_power, int pv_power);
    ~Network();
};
