#pragma once

#include <math.h>
#include "defines.h"
#include "config.h"

// 50.44053359846769, 30.429290808550714
// 50.446142907512304, 30.45123831744762
// 1700m

double inline dis(
  double lat1, double lon1,
  double lat2, double lon2) {

    double dLat = (lat2 - lat1);
    double dLon = (lon2 - lon1);
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;

}

double inline flightTime(double distance)
{
  return distance * DRONE_MAXIMUX_SPEED_M_MIN;
}