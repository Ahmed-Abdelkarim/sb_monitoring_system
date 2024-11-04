#include "sbStorage.h"

sbStorage::sbStorage()
{
    //default: basic
    nb_inverters = 1;
    nb_modules = 2;
    nb_controllers = 1;
    storage = 0;
    energyFromGrid = 0;
    energyToGrid = 0;
    network_ptr = std::make_shared<Network>();
}
void sbStorage::setup(SETUP s){
    switch (s)
    {
    case BASIC:
        nb_inverters = 1;
        nb_modules = 2;
        nb_controllers = 1;
        capacity = 20;
        break;
    case STANDARD:
        nb_inverters = 1;
        nb_modules = 3;
        nb_controllers = 1;
        capacity = 30;
        break;
    case PRO:
        nb_inverters = 1;
        nb_modules = 5;
        nb_controllers = 1;
        capacity = 50;
        break;
    default:
        break;
    }
    
}
void sbStorage::setChargeMode(int m){
    charge_mode = (MODE)m;
}
int sbStorage::getStorage(){
    return storage;
}
void sbStorage::energeAlgo(){
    production =  network_ptr->pv_ptr->getPower();
    consumption = network_ptr->hg_ptr->getPower();
    if(production > consumption){
        setChargeMode(0); //CHARGING
        int surplus = production - consumption;
        storage = surplus > capacity? capacity : surplus;
        energyToGrid += surplus - storage;
        network_ptr->g_ptr->addPower(energyToGrid);
    }
    else{
        setChargeMode(1); //DISCHARGING
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