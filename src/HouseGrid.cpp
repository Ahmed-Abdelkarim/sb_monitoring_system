#include "HouseGrid.h"

HouseGrid::HouseGrid(int f)
{
    frequency = f;
}

void HouseGrid::setPower(int p){
    power = p;
}
int HouseGrid::getPower(){
    return power;
}
void HouseGrid::setCurrent(int I){
    current = I;
}
int HouseGrid::getCurrent(){
    return current;
}
void HouseGrid::setVoltage(int V){
    voltage = V;
}
int HouseGrid::getVoltage(){
    return voltage;
}
int HouseGrid::getFreq(){
    return frequency;
}
