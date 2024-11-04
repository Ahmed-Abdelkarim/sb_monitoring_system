#pragma once
#include "PowerEntity.h"

class PV : public PowerEntity
{
private:
    int nb_panels;
public:
    PV(int n);
    void setPower(int p);
    int getPower();
    void setCurrent(int I);
    int getCurrent();
    void setVoltage(int V);
    int getVoltage();
    ~PV();
};
