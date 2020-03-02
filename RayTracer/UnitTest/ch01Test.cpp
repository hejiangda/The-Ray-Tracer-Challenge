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
