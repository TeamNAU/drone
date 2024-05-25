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

bool DeliveryCenter::getOrder(Package package)
{
    double dist2target = dis(baseLat, baseLon, package._location.lat, package._location.lon);
    if (dist2target > coverageDistance)
    {
        printf("The ordering point is too far away (%.2f > %.2f). Delivery is not possible.\n", dist2target, (float)coverageDistance);
        return false;
    }
    double flyTime = flightTime(dist2target);
    printf("delivery distance: %f\n", dist2target);
    printf("delivery time: %d\n", (int)flyTime);
    printf("\t----Package Info----\n");
    printf("Weight: %lf\n", package._weight);
    printf("Height: %d\n", package._format._height);
    printf("Width: %d\n", package._format._width);
    return true;
}

void DeliveryCenter::createOrder()
{
    double weight = UI.setWeight();
    LocationData locData = UI.setCoordinates();
    Format format = UI.setFormat();

    UI.isOrderAccepted(getOrder(Package(weight, locData, format)));    
}