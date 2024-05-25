#include "UserInterface.h"
#include "stdio.h"

UserInterface::UserInterface(/* args */)
{
}

UserInterface::~UserInterface()
{
}

LocationData UserInterface::setCoordinates()
{
    LocationData locData;
    printf("Input order coordinates:\n");
    printf("\tLat: ");
    scanf("%lf", &locData.lat);
    printf("\tLon: ");
    scanf("%lf", &locData.lon);
    return locData;
}

double UserInterface::setWeight()
{
    double weight;
    printf("Input order weight:\n");
    printf("\tweight (g): ");
    scanf("%lf", &weight);
    return weight;
}

Format UserInterface::setFormat()
{
    Format size;
    printf("Input order size:\n");
    printf("\twidth (cm): ");
    scanf("%d", &size._width);
    printf("\theight (cm): ");
    scanf("%d", &size._height);
    return size;
}

void UserInterface::isOrderAccepted(bool deliverAbility)
{
    if (deliverAbility == false)
    {
        printf("Order rejected.\n");
    }
    else
    {
        printf("Order accepted. Please wait delivery.\n");
    }
}
