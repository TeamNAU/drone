#include "test_runner.h"
#include "Battery.h"
#include "Drone.h"
#include "DeliveryCenter.h"

#include <vector>
#include <array>
#include <sys/resource.h>

using namespace std;

void TestBattery()
{
    Battery b;
    ASSERT_EQUAL(b.getBatteryLevel(), 0);
    b.setBatteryLevel(100);
    ASSERT_EQUAL(b.getBatteryLevel(), 100);
    b.setBatteryLevel(0);
    for(int i = 0; i < 20; i++)
        b.Charge();
    ASSERT_EQUAL(b.getBatteryLevel(), 60);
}

void TestDrone()
{
    Drone d;
    ASSERT_EQUAL(d.getBatteryLevel(), 100);
    ASSERT_EQUAL(d.LowLevel(), false);
    ASSERT_EQUAL(d.needBatteryCharge(), false);
    ASSERT_EQUAL(d.deliveryStart(), true);
    ASSERT_EQUAL(d.isDelivery(), true);
    int deliveryTime = 90;
    for(int i = 0; i < deliveryTime; i++)
        d.delivery();
    ASSERT_EQUAL(d.getDistanceAfterStartDelivery(), (deliveryTime * DRONE_MAXIMUX_SPEED_M_MIN));
    ASSERT_EQUAL(d.getTimeAfterStartDelivery(), deliveryTime);
    d.deliveryFinish();
    ASSERT_EQUAL(d.getBatteryLevel(), 9);
    ASSERT_EQUAL(d.LowLevel(), true);
    ASSERT_EQUAL(d.isDelivery(), false);
    ASSERT_EQUAL(d.deliveryStart(), false);
    ASSERT_EQUAL(d.needBatteryCharge(), true);
    for(int i = 0; i < 24; i++)
        d.Charge();
    ASSERT_EQUAL(d.needBatteryCharge(), false);
    ASSERT_EQUAL(d.getBatteryLevel(), 81);
}

void TestDeliveryCenter()
{
    DeliveryCenter dc(1);
    // double baseLat=50.44053359846769;
    // double baseLon=30.429290808550714;
    double w = 123.1;
    LocationData ld;
    ld.lat=50.446142907512304;
    ld.lon=30.45123831744762;
    Format f;
    f._height=45;
    f._width=67;
    ASSERT_EQUAL(dc.getOrder(Package(w, ld, f)), true);
    // 50.08754251560169, 30.3204470926092
    ld.lat=50.08754251560169;
    ld.lon=30.3204470926092;
    ASSERT_EQUAL(dc.getOrder(Package(w, ld, f)), false);
}

int main() 
{
    TestRunner tr;
    RUN_TEST(tr, TestBattery);
    RUN_TEST(tr, TestDrone);
    RUN_TEST(tr, TestDeliveryCenter);
    return 0;
}