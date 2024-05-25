#pragma once
#include "Location.h"
#include "Package.h"

class UserInterface
{
public:
    UserInterface(/* args */);
    ~UserInterface();

    LocationData setCoordinates();
    double setWeight();
    Format setFormat();
    void isOrderAccepted(bool deliverAbility);
};
