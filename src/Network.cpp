#include "Network.h"

Network::Network()
{
    //power network init
    //house init
    hg_ptr = std::make_shared<HouseGrid>(30); // freq = 30
    hg_ptr->setPower(10);
    hg_ptr->setCurrent(1);
    hg_ptr->setVoltage(12);

    //grid init
    g_ptr = std::make_shared<Grid>(30); // frequency = 30
    g_ptr->setPower(1000);
    g_ptr->setCurrent(1);
    g_ptr->setVoltage(12);

    //pv init
    pv_ptr = std::make_shared<PV>(9); // panels # = 9
    pv_ptr->setPower(5);
    pv_ptr->setCurrent(1);
    pv_ptr->setVoltage(12);

}
void Network::updatePower(int house_power, int grid_power, int pv_power){
    hg_ptr->setPower(house_power);
    g_ptr->setPower(grid_power);
    pv_ptr->setPower(pv_power);
}
Network::~Network()
{
}
