#include "Drone.h"
#include <stdio.h>

Drone::Drone(/* args */)
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

bool Drone::flyStart()
{
    inFlight = true;
    if (LowLevel())
    {
        printf("Flight is not possible. Please charge drone\n");
        needCharge = true;
        return false;
    }
    printf("Flight start\n");
    info();
    Battery.setBatteryLevel(Battery.getBatteryLevel() - BATTERY_USE_PER_MINUTE);
    return true;
}

void Drone::flyFinish()
{
    inFlight = false;
    if (LowLevel())
    {
        printf("Please charge drone\n");
        needCharge = true;
    }
    printf("Flight finish\n");
}

void Drone::fly()
{
    Battery.setBatteryLevel(Battery.getBatteryLevel() - BATTERY_USE_PER_MINUTE);
}

bool Drone::isFly()
{
    return inFlight;
}

void Drone::info()
{
    int flightDistance = (Battery.getBatteryLevel() - BATTERY_RESERV_LEVEL) * DRONE_MAXIMUX_SPEED_M_MIN;
    int flightTime = (Battery.getBatteryLevel() - BATTERY_RESERV_LEVEL) / BATTERY_USE_PER_MINUTE;
    printf("Drone info:\n");
    printf("\tBattery level: %d\n", Battery.getBatteryLevel());
    printf("\tPossible flight distance: %d m\n", flightDistance);
    printf("\tPossible flight time: %d minutes\n", flightTime);
    printf("\tReserv flight distance: %d m\n", RESERV_FLIGHT_DISTANCE);
    printf("\tReserv flight time: %d minutes\n", RESERV_FLIGHT_TIME);
}