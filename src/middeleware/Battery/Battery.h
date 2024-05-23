#pragma once

class Battery
{
public:
    Battery(/* args */);
    ~Battery();

    int getBatteryLevel();
    void setBatteryLevel(int newBatteryLevel);
    void Charge();

private:
    int batteryLevel;
};