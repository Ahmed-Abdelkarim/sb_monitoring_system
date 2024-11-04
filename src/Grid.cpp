#include "Grid.h"


Grid::Grid(int f)
{
    frequency = f;
}
void Grid::addPower(int p){
    power += p;
}
Grid::~Grid()
{
}


void Grid::setPower(int p){
    power = p;
}
int Grid::getPower(){
    return power;
}
void Grid::setCurrent(int I){
    current = I;
}
int Grid::getCurrent(){
    return current;
}
void Grid::setVoltage(int V){
    voltage = V;
}
int Grid::getVoltage(){
    return voltage;
}
