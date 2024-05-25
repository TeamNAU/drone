#pragma once

#include <memory>
#include <thread>

struct LocationData
{
    double lon;
    double lat;
    double heading;
    double speed;
    double altitude;
};

enum class LocationStatus
{
    NOT_FIX,
    FIX_2D,
    FIX_3D
};

// class ILocationListener
// {
// public:
//     virtual ~ILocationListener() = default;
//     virtual void onLocationUpdate(const std::shared_ptr<LocationData> locationInfo) = 0;
//     virtual void onLocationStatusUpdate(const std::shared_ptr<LocationData> locationStatus) = 0;
// };

// class ILocationManager
// {
// public:
//     virtual bool getStatus() = 0;
//     virtual bool registerLocationEventLisener(std::shared_ptr<ILocationListener> listener);
//     virtual bool unregisterLocationEventLisener();
//     virtual bool std::thread& startListening;
//     virtual ~ILocationManager() = default;
// };