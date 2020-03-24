#include "UnitTest.h"

TEST(Intersections,IntersectionEncapsulateTAndObject) {
    RSphere s;
    RIntersection i(3.5,s);
    EXPECT_FLOAT_EQ(i.t,3.5);
    EXPECT_EQ(i.obj,s);
}
TEST(Intersections,AggregatingIntersections) {
    RSphere s;
    RIntersection i1(1,s);
    RIntersection i2(2,s);
    vector<RIntersection> xs=RIntersection::intersections({i1,i2});
    ASSERT_EQ(xs.size(),2);
    EXPECT_FLOAT_EQ(xs[0].t,1);
    EXPECT_FLOAT_EQ(xs[1].t,2);
}
