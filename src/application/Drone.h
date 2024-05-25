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
    bool deliveryStart();
    void deliveryFinish();
    void delivery();
    bool isDelivery();
    void info();
    int getDistanceAfterStartDelivery();
    int getTimeAfterStartDelivery();

private:
    Battery Battery;
    bool needCharge;
    bool inDelivery;
    int distanceAfterStart;
};
