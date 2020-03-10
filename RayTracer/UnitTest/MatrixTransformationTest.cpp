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
