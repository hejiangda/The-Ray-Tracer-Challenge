#include "tst_tuples.h"

TEST(Tuples,point)
{
    RTuple a(4.3,-4.2,3.1,1.0);
    ASSERT_EQ(a.x,float(4.3));
    ASSERT_EQ(a.y,float(-4.2));
    ASSERT_EQ(a.z,float(3.1));
    ASSERT_EQ(a.w,float(1.0));
    ASSERT_EQ(a.type(),POINT);
    ASSERT_NE(a.type(),VECTOR);
}
TEST(Tuples,vector)
{
    RTuple a(4.3,-4.2,3.1,0.0);
    ASSERT_EQ(a.x,float(4.3));
    ASSERT_EQ(a.y,float(-4.2));
    ASSERT_EQ(a.z,float(3.1));
    ASSERT_EQ(a.w,float(0.0));
    ASSERT_NE(a.type(),POINT);
    ASSERT_EQ(a.type(),VECTOR);
}
TEST(Tuples,CreatePoint) {
    RPoint p(4,-4,3);
    ASSERT_EQ(p,RTuple(4,-4,3,1));
}
TEST(Tuples,CreateVector) {
    RVector v(4,-4,3);
    ASSERT_EQ(v,RTuple(4,-4,3,0));
}
TEST(Operations,TupleAdd) {
    RTuple a1(3,-2,5,1),a2(-2,3,1,0);
    ASSERT_EQ(a1+a2,RTuple(1,1,6,1));
}
TEST(Operations,PointSub) {
    RPoint p1(3,2,1),p2(5,6,7);
    ASSERT_EQ(p1-p2,RVector(-2,-4,-6));
}
TEST(Operations,PointSubVector) {
    RPoint p(3,2,1);
    RVector v(5,6,7);
    ASSERT_EQ(p-v,RPoint(-2,-4,-6));
}
TEST(Operations,VectorSub) {
    RVector v1(3,2,1),v2(5,6,7);
    ASSERT_EQ(v1-v2,RVector(-2,-4,-6));
}
TEST(Operations,ZeroSubVector) {
    RVector zero,v(1,-2,3);
    ASSERT_EQ(zero-v,RVector(-1,2,-3));
}
TEST(Operations,NegativeTuple) {
    RTuple v(1,-2,3,-4);
    ASSERT_EQ(-v,RTuple(-1,2,-3,4));
}
