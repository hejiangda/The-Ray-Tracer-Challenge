#include "UnitTest.h"

TEST(MatrixTrans,translation) {
    RMatrix4 transform;
    transform.toIdentity();
    transform.translation(5,-3,2);
    RPoint p(-3,4,5);
    EXPECT_EQ(transform*p,RPoint(2,1,7));
}

TEST(MatrixTrans,inverseTranslation) {
    RMatrix4 transform;
    transform.toIdentity();
    transform.translation(5,-3,2);
    RMatrix4 inv=transform.inverse();
    RPoint p(-3,4,5);
    EXPECT_EQ(inv*p,RPoint(-8,7,3));
}

TEST(MatrixTrans,noEffectOnVectors) {
    RMatrix4 transform;
    transform.toIdentity();
    transform.translation(5,-3,2);
    RVector v(-3,4,5);
    EXPECT_EQ(transform*v,v);
}
TEST(MatrixTrans,ScalingPoint) {
    RMatrix4 transform;
    transform.scale(2,3,4);
    RPoint p(-4,6,8);
    EXPECT_EQ(transform*p,RPoint(-8,18,32));
}
TEST(MatrixTrans,ScalingVector) {
    RMatrix4 transform;
    transform.scale(2,3,4);
    RVector v(-4,6,8);
    EXPECT_EQ(transform*v,RVector(-8,18,32));
}
TEST(MatrixTrans,multiplyInverseScale) {
    RMatrix4 transform;
    transform.scale(2,3,4);
    RMatrix4 inv=transform.inverse();
    RVector v(-4,6,8);
    EXPECT_EQ(inv*v,RVector(-2,2,2));
}
TEST(MatrixTrans,Reflection) {
    RMatrix4 transform;
    transform.scale(-1,1,1);
    RPoint p(2,3,4);
    EXPECT_EQ(transform*p,RPoint(-2,3,4));
}

TEST(MatrixTrans,RotatingXAxis) {
    RPoint p(0,1,0);
    RMatrix4 half_quarter;
    half_quarter.rotation_x(M_PI_4);
    RMatrix4 full_quarter;
    full_quarter.rotation_x(M_PI_2);

    EXPECT_EQ(half_quarter*p,RPoint(0,sqrt(2)/2,sqrt(2)/2));
    EXPECT_EQ(full_quarter*p,RPoint(0,0,1));

}
TEST(MatrixTrans,invRotatingXAxis) {
    RPoint p(0,1,0);
    RMatrix4 half_quarter;
    half_quarter.rotation_x(M_PI_4);
    RMatrix4 inv=half_quarter.inverse();
    EXPECT_EQ(inv*p,RPoint(0,sqrt(2)/2,-sqrt(2)/2));
}
TEST(MatrixTrans,RotatingYAxis) {
    RPoint p(0,0,1);
    RMatrix4 half_quarter;
    half_quarter.rotation_y(M_PI_4);
    RMatrix4 full_quarter;
    full_quarter.rotation_y(M_PI_2);

    EXPECT_EQ(half_quarter*p,RPoint(sqrt(2)/2,0,sqrt(2)/2));
    EXPECT_EQ(full_quarter*p,RPoint(1,0,0));

}
TEST(MatrixTrans,RotatingZAxis) {
    RPoint p(0,1,0);
    RMatrix4 half_quarter;
    half_quarter.rotation_z(M_PI_4);
    RMatrix4 full_quarter;
    full_quarter.rotation_z(M_PI_2);

    EXPECT_EQ(half_quarter*p,RPoint(-sqrt(2)/2,sqrt(2)/2,0));
    EXPECT_EQ(full_quarter*p,RPoint(-1,0,0));

}
