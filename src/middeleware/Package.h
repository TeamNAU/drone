#pragma once
#include "Location.h"

struct Format
{
    int _width;
    int _height;
};


struct Package
{
    double _weight;
    LocationData _location;
    Format _format;
    Package(double w, LocationData ld, Format s) : _weight(w), _location(ld), _format(s){};
};
