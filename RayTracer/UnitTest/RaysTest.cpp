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
TEST(Rays,TranslatingARay) {
    RRay r(RPoint(1,2,3),RVector(0,1,0));
    RMatrix4 m;
    m.translation(3,4,5);
    RRay r2=r.transform(m);

    EXPECT_EQ(r2.origin,RPoint(4,6,8));
    EXPECT_EQ(r2.direction,RVector(0,1,0));
}
TEST(Rays,ScalingARay) {
    RRay r(RPoint(1,2,3),RVector(0,1,0));
    RMatrix4 m;
    m.scale(2,3,4);
    RRay r2=r.transform(m);

    EXPECT_EQ(r2.origin,RPoint(2,6,12));
    EXPECT_EQ(r2.direction,RVector(0,3,0));
}
