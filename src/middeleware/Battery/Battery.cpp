#include "Battery.h"
#include <stdio.h>
#include "../config.h"

Battery::Battery() : batteryLevel(0)
{}

Battery::~Battery()
{}

int Battery::getBatteryLevel()
{
    return batteryLevel;
}

void Battery::setBatteryLevel(int newBatteryLevel)
{
    batteryLevel = newBatteryLevel;
}

void Battery::Charge()
{
    if(batteryLevel < 100)
    {
        printf("Battery Charging: %d\n", batteryLevel);
        batteryLevel += BATTERY_CHARGING_PER_MINUTE;
    }
    else
    {
        printf("Battery Full\n");
    }
}
