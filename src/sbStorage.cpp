#include "sbStorage.h"

sbStorage::sbStorage(std::unique_ptr<Network> network_ptr) : network_ptr_(std::move(network_ptr))
{
    //default: basic
    nb_inverters = 1;
    nb_modules = 2;
    nb_controllers = 1;
    storage = 0;
    energyFromGrid = 0;
    energyToGrid = 0;
    
}
void sbStorage::setup(SETUP s){
    switch (s)
    {
    case BASIC:
        nb_inverters = 1;
        nb_modules = 2;
        nb_controllers = 1;
        break;
    case STANDARD:
        nb_inverters = 1;
        nb_modules = 3;
        nb_controllers = 1;
        break;
    case PRO:
        nb_inverters = 1;
        nb_modules = 5;
        nb_controllers = 1;
        break;
    default:
        break;
    }
    capacity = nb_modules * 10;
}
void sbStorage::setChargeMode(int m){
    charge_mode = (MODE)m;
}
int sbStorage::getStorage(){
    return storage;
}
void sbStorage::energeAlgo(){
    production =  network_ptr_->pv_ptr->getPower();
    consumption = network_ptr_->hg_ptr->getPower();
    if(production > consumption){
        setChargeMode(0); //CHARGING
        int surplus = production - consumption;
        storage = surplus > capacity? capacity : surplus;
        energyToGrid += surplus - storage;
        network_ptr_->g_ptr->addPower(energyToGrid);
    }
    else{
        setChargeMode(1); //DISCHARGING
        consumption -= production;
        storage = consumption > storage? 0: storage-consumption;
        energyFromGrid = storage? 0 : consumption - storage;
    }
}
int sbStorage::getPowerToGrid(){
    return energyToGrid;
}
int sbStorage::getPowerFromGrid(){
    return energyFromGrid;
}
sbStorage::~sbStorage()
{
}