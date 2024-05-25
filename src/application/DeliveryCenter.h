#pragma once

#include "Drone.h"
#include "UserInterface.h"
class DeliveryCenter
{
public:
    DeliveryCenter(int dronesNumber);
    ~DeliveryCenter();
    bool getOrder(Package package);
    void createOrder();
private:
    double baseLat = BASE_LAT;
    double baseLon = BASE_LON;

    Drone *drones = nullptr;
    int dronesNumber = 0;
    int coverageDistance = 0;
    int cargoCapacity = 0;

    UserInterface UI;
};

