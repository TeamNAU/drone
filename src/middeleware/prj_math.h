#pragma once

#include <math.h>
#include "defines.h"
#include "config.h"

// 50.44053359846769, 30.429290808550714
// 50.446142907512304, 30.45123831744762
// 1700m
#define d2r (M_PI / 180.0)
double inline dis(
  const double lat1, const double lon1,
  const double lat2, const double lon2) {
  // printf("b lat : %f\n", lat1);
  // printf("b lon : %f\n", lon1);
  // printf("o lat : %f\n", lat2);
  // printf("o lon : %f\n", lon2);
  double dlong = (lon2 - lon1) * d2r;
  double dlat = (lat2 - lat1) * d2r;
  double a = pow(sin(dlat / 2.0), 2) + cos(lat1 * d2r) * cos(lat2 * d2r) * pow(sin(dlong / 2.0), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return EARTH_RADIUS * c;

}

double inline flightTime(double distance)
{
  return (distance / DRONE_MAXIMUX_SPEED_M_MIN);
}