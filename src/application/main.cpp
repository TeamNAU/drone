#include "Drone.h"
#include <stdio.h>

int main()
{
    Drone d;
    d.flyStart();
    for (int minutes = 0; minutes < 140; minutes++)
    {
        printf("\tminute: %d\n", minutes);
        if(d.getBatteryLevel() == 10)
            d.flyFinish();
        if(d.isFly())
        {
            d.info();
            d.fly();
        }
        else 
            d.Charge();
    }
    return 0;
}