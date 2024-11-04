#include "PV.h"


PV::PV(int n)
{
    nb_panels = n;
}

PV::~PV()
{
}


void PV::setPower(int p){
    power = p;
}
int PV::getPower(){
    return power;
}
void PV::setCurrent(int I){
    current = I;
}
int PV::getCurrent(){
    return current;
}
void PV::setVoltage(int V){
    voltage = V;
}
int PV::getVoltage(){
    return voltage;
}