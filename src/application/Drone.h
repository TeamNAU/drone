#pragma once
#include "../middeleware/Battery/Battery.h"
#include "../middeleware/config.h"

class Drone
{
public:
    Drone(/* args */);
    ~Drone();
    void Charge();
    bool LowLevel();
    int getBatteryLevel();
    bool needBatteryCharge();
    bool flyStart();
    void flyFinish();
    void fly();
    bool isFly();
    void info();

private:
    Battery Battery;
    bool needCharge;
    bool inFlight;
};
