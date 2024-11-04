#pragma once
#include "PowerEntity.h"

class HouseGrid : public PowerEntity
{

protected:
    int frequency;
public:
    HouseGrid(int f);
    void setPower(int p);
    int getPower();
    void setCurrent(int I);
    int getCurrent();
    void setVoltage(int V);
    int getVoltage();
};
