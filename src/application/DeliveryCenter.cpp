#include <stdio.h>
#include "DeliveryCenter.h"
#include "prj_math.h"
#include "defines.h"

DeliveryCenter::DeliveryCenter(int dronesNumber) : dronesNumber(dronesNumber),
                                                   cargoCapacity(DRONE_CARGO_CAPACITY_KG)
{
    drones = new Drone[dronesNumber];
    coverageDistance = ((MAX_BATTERY_LEVEL - BATTERY_RESERV_LEVEL) * (DRONE_MAXIMUX_SPEED_M_S * SEC_TO_MIN)) / 2;
    printf("\t**** Delivery Center Info ****\n");
    printf("Number of drones: %d\n", dronesNumber);
    printf("Coverage distance: %d meters\n", coverageDistance);
    printf("Cargo capacity: %d kilograms\n", cargoCapacity);
}

DeliveryCenter::~DeliveryCenter()
{
    delete[] drones;
}

bool DeliveryCenter::getOrder(double lat, double lon)
{
    double dist2target = dis(50.44053359846769, 30.429290808550714, lat, lon);
    if (dist2target > coverageDistance)
    {
        printf("The ordering point is too far away (%.2f > %.2f). Delivery is not possible.", dist2target, (float)coverageDistance);
        return false;
    }
    double flyTime = flightTime(dist2target);
    printf("delivery distance: %f\n", dist2target);
    printf("delivery time: %d\n", (int)flyTime);
}