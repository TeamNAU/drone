#include "Drone.h"
#include <stdio.h>

Drone::Drone(/* args */) : needCharge(false)
{
    Battery.setBatteryLevel(100);
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
    printf("Delivery start\n");
    info();
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
    printf("Delivery finish\n");
}

void Drone::delivery()
{
    Battery.setBatteryLevel(Battery.getBatteryLevel() - BATTERY_USE_PER_MINUTE);
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