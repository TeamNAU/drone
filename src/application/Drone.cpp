#include "Drone.h"
#include <stdio.h>

Drone::Drone(/* args */) : needCharge(false)
{
    Battery.setBatteryLevel(100);
    distanceAfterStart = 0;
}

Drone::~Drone()
{
}

void Drone::Charge()
{
    Battery.Charge();
    if (Battery.getBatteryLevel() > 80)
        needCharge = false;
}

bool Drone::LowLevel()
{
    return Battery.getBatteryLevel() < BATTERY_RESERV_LEVEL ? true : false;
}
int Drone::getBatteryLevel()
{
    if (LowLevel())
        needCharge = true;
    return Battery.getBatteryLevel();
}

bool Drone::needBatteryCharge()
{
    return needCharge;
}

bool Drone::deliveryStart()
{
    if (LowLevel())
    {
        printf("Delivery is not possible. Please charge drone\n");
        needCharge = true;
        return false;
    }
    printf("\t\t----Delivery start----\n");
    info();
    distanceAfterStart = 0;
    Battery.setBatteryLevel(Battery.getBatteryLevel() - BATTERY_USE_PER_MINUTE);
    inDelivery = true;
    return true;
}

void Drone::deliveryFinish()
{
    inDelivery = false;
    if (LowLevel())
    {
        printf("Please charge drone\n");
        needCharge = true;
    }
    printf("\t\t----Delivery finish----\n");
    printf("\tDistance: %d m\n", getDistanceAfterStartDelivery());
    printf("\tTime: %d minutes\n", getTimeAfterStartDelivery());
}

void Drone::delivery()
{
    Battery.setBatteryLevel(Battery.getBatteryLevel() - BATTERY_USE_PER_MINUTE);
    distanceAfterStart = distanceAfterStart + DRONE_MAXIMUX_SPEED_M_MIN;
    printf("\n\tDelivery in process...\n");
    printf("Distance after start: %d m\n", getDistanceAfterStartDelivery());
    printf("Time after start: %d minutes\n", getTimeAfterStartDelivery());
}

bool Drone::isDelivery()
{
    return inDelivery;
}

void Drone::info()
{
    int deliveryDistance = (Battery.getBatteryLevel() - BATTERY_RESERV_LEVEL) * DRONE_MAXIMUX_SPEED_M_MIN;
    int deliveryTime = (Battery.getBatteryLevel() - BATTERY_RESERV_LEVEL) / BATTERY_USE_PER_MINUTE;
    printf("Drone info:\n");
    printf("\tBattery level: %d\n", Battery.getBatteryLevel());
    printf("\tPossible delivery distance: %d m\n", deliveryDistance);
    printf("\tPossible delivery time: %d minutes\n", deliveryTime);
    printf("\tReserv delivery distance: %d m\n", RESERV_DELIVERY_DISTANCE);
    printf("\tReserv delivery time: %d minutes\n", RESERV_DELIVERY_TIME);
}

int Drone::getDistanceAfterStartDelivery()
{
    return distanceAfterStart;
}

int Drone::getTimeAfterStartDelivery()
{
    return (distanceAfterStart / DRONE_MAXIMUX_SPEED_M_MIN) * BATTERY_USE_PER_MINUTE;
}