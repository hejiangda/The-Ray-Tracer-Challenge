#include "ch01Test.h"

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
TEST(Operations,ScalarMultiply1) {
    RTuple a(1,-2,3,-4);
    ASSERT_EQ(a*3.5,RTuple(3.5,-7,10.5,-14));
    ASSERT_EQ(3.5*a,RTuple(3.5,-7,10.5,-14));
}
TEST(Operations,ScalarMultiply2) {
    RTuple a(1,-2,3,-4);
    ASSERT_EQ(a*0.5,RTuple(0.5,-1,1.5,-2));
    ASSERT_EQ(0.5*a,RTuple(0.5,-1,1.5,-2));
}
TEST(Operations,ScalarDiv) {
    RTuple a(1,-2,3,-4);
    ASSERT_EQ(a/2,RTuple(0.5,-1,1.5,-2));
}
TEST(Operations,Magnitude1) {
    RVector v(1,0,0);
    ASSERT_TRUE(floatCmp(1.0,magnitude(v)));
    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude2) {
    RVector v(0,1,0);
    ASSERT_TRUE(floatCmp(1.0,magnitude(v)));
    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude3) {
    RVector v(0,0,1);
    ASSERT_TRUE(floatCmp(1.0,magnitude(v)));
    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude4) {
    RVector v(1,2,3);
    ASSERT_TRUE(floatCmp(sqrt(14),magnitude(v)));
    ASSERT_TRUE(floatCmp(sqrt(14),v.magnitude()));
}
TEST(Operations,Normalize1) {
    RVector v(4,0,0);
    ASSERT_EQ(normalize(v),RVector(1,0,0));
    ASSERT_EQ(v.normalize(),RVector(1,0,0));
}
TEST(Operations,Normalize2) {
    RVector v(1,2,3);
    ASSERT_EQ(normalize(v),RVector(1/sqrt(14),2/sqrt(14),3/sqrt(14)));
    ASSERT_EQ(v.normalize(),RVector(1/sqrt(14),2/sqrt(14),3/sqrt(14)));
}
TEST(Operations,Normalize3) {
    RVector v(1,2,3);
    RVector norm=v.normalize();
    ASSERT_TRUE(floatCmp(1.0,magnitude(norm)));
    ASSERT_TRUE(floatCmp(1.0,norm.magnitude()));

}
