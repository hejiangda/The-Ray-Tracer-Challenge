#include "UnitTest.h"

TEST(Rays,CreateARay) {
    RPoint origin(1,2,3);
    RVector direction(4,5,6);
    RRay r(origin,direction);
    EXPECT_EQ(r.origin,origin);
    EXPECT_EQ(r.direction,direction);
}
TEST(Rays,ComputeAPointFromADistance) {
    RRay r(RPoint(2,3,4),RVector(1,0,0));
    EXPECT_EQ(r.position(0),RPoint(2,3,4));
    EXPECT_EQ(r.position(1),RPoint(3,3,4));
    EXPECT_EQ(r.position(-1),RPoint(1,3,4));
    EXPECT_EQ(r.position(2.5),RPoint(4.5,3,4));
}
