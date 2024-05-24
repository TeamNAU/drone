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
    ASSERT_EQUAL(d.flyStart(), true);
    ASSERT_EQUAL(d.isFly(), true);
    for(int i = 0; i < 90; i++)
        d.fly();
    d.flyFinish();
    ASSERT_EQUAL(d.getBatteryLevel(), 9);
    ASSERT_EQUAL(d.LowLevel(), true);
    ASSERT_EQUAL(d.isFly(), false);
    ASSERT_EQUAL(d.flyStart(), false);
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
    double orderLat=50.446142907512304;
    double orderLon=30.45123831744762;
    ASSERT_EQUAL(dc.getOrder(orderLat, orderLon), true);
    // 50.08754251560169, 30.3204470926092
    orderLat=50.08754251560169;
    orderLon=30.3204470926092;
    ASSERT_EQUAL(dc.getOrder(orderLat, orderLon), false);
}

int main() 
{
    TestRunner tr;
    RUN_TEST(tr, TestBattery);
    RUN_TEST(tr, TestDrone);
    RUN_TEST(tr, TestDeliveryCenter);
    return 0;
}