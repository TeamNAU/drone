#include "Drone.h"
#include "DeliveryCenter.h"
#include <stdio.h>

int main()
{
    DeliveryCenter dc(2);

    // 50.44053359846769, 30.429290808550714
    // 50.446142907512304, 30.45123831744762
    // 1700m
    // dc.getOrder(50.446142907512304, 30.45123831744762);
    dc.createOrder();
    return 0;
}