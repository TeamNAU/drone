#pragma once

#include "Drone.h"

class DeliveryCenter
{
public:
    DeliveryCenter(int dronesNumber);
    ~DeliveryCenter();
    bool getOrder(double lat, double lon);
private:
    Drone *drones = nullptr;
    int dronesNumber = 0;
    int coverageDistance = 0;
    int cargoCapacity = 0;
};

