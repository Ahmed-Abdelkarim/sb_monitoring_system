#pragma once
#include "PowerEntity.h"

class Grid : public PowerEntity
{
private:
    int frequency;
public:
    Grid(int f);
    void addPower(int p);
    void setPower(int p);
    int getPower();
    void setCurrent(int I);
    int getCurrent();
    void setVoltage(int V);
    int getVoltage();
    int getFreq();
    ~Grid();
};
