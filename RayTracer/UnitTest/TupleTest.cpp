#include "UnitTest.h"
TEST(Tuples,squareBracket) {
    RTuple a({4.3,-4.2,3.1,1.0});
    RTuple b;
    b[0]=4.3;
    b[1]=-4.2;
    b[2]=3.1;
    b[3]=1.0;
    ASSERT_EQ(a,b);
}
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
TEST(Operations,VectorScalarMultiply){
    RVector a(1,-2,3);
    EXPECT_EQ(a*0.5,RVector(0.5,-1,1.5));
    EXPECT_EQ(0.5*a,RVector(0.5,-1,1.5));
}
TEST(Operations,PointScalarMultiply){
    RPoint a(1,-2,3);
    EXPECT_EQ(a*0.5,RPoint(0.5,-1,1.5));
    EXPECT_EQ(0.5*a,RPoint(0.5,-1,1.5));
}
TEST(Operations,ScalarDiv) {
    RTuple a(1,-2,3,-4);
    ASSERT_EQ(a/2,RTuple(0.5,-1,1.5,-2));
}
TEST(Operations,Magnitude1) {
    RVector v(1,0,0);

    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude2) {
    RVector v(0,1,0);

    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude3) {
    RVector v(0,0,1);

    ASSERT_TRUE(floatCmp(1.0,v.magnitude()));
}
TEST(Operations,Magnitude4) {
    RVector v(1,2,3);

    ASSERT_TRUE(floatCmp(sqrt(14),v.magnitude()));
}
TEST(Operations,Normalize1) {
    RVector v(4,0,0);

    ASSERT_EQ(v.normalize(),RVector(1,0,0));
}
TEST(Operations,Normalize2) {
    RVector v(1,2,3);

    ASSERT_EQ(v.normalize(),RVector(1/sqrt(14),2/sqrt(14),3/sqrt(14)));
}
TEST(Operations,Normalize3) {
    RVector v(1,2,3);
    RVector norm=v.normalize();

    ASSERT_TRUE(floatCmp(1.0,norm.magnitude()));
}
TEST(Operations,DotProduct) {
    RVector a(1,2,3),b(2,3,4);
    ASSERT_TRUE(floatCmp(a*b,20));
}
TEST(Operations,CrossProduct) {
    RVector a(1,2,3),b(2,3,4);
    ASSERT_EQ(a&b,RVector(-1,2,-1));
    ASSERT_EQ(b&a,RVector(1,-2,1));
}

TEST(Colors,Object) {
    RColor c(-0.5,0.4,1.7);
    ASSERT_TRUE(floatCmp(c.r,-0.5));
    ASSERT_TRUE(floatCmp(c.g,0.4));
    ASSERT_TRUE(floatCmp(c.b,1.7));
}

TEST(Colors,Add) {
    RColor c1(0.9,0.6,0.75),c2(0.7,0.1,0.25);
    ASSERT_EQ(c1+c2,RColor(1.6, 0.7, 1.0));
}
TEST(Colors,Sub) {
    RColor c1(0.9,0.6,0.75),c2(0.7,0.1,0.25);
    ASSERT_EQ(c1-c2,RColor(0.2, 0.5, 0.5));
}
TEST(Colors,ScalarMultiply) {
    RColor c1(0.2, 0.3, 0.4);
    ASSERT_EQ(2*c1,RColor(0.4, 0.6, 0.8));
    ASSERT_EQ(c1*2,RColor(0.4, 0.6, 0.8));
}
TEST(Colors,ColorMultiply) {
    RColor c1(1, 0.2, 0.4),c2(0.9, 1, 0.1);
    ASSERT_EQ(c1*c2,RColor(0.9, 0.2, 0.04));
}
