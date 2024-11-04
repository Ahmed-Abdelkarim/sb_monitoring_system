#pragma once
class PowerEntity
{
protected:
    int power;
    int current;
    int voltage;
public:
    virtual void setPower(int p) = 0;
    virtual int getPower() = 0;
    virtual void setCurrent(int I) = 0;
    virtual int getCurrent() = 0;
    virtual void setVoltage(int V) = 0;
    virtual int getVoltage() = 0;
};
