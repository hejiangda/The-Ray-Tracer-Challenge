#include "UnitTest.h"

TEST(Intersections,IntersectionEncapsulateTAndObject) {
    RSphere s;
    RIntersection i(3.5,&s);
    EXPECT_FLOAT_EQ(i.t,3.5);
    EXPECT_EQ(*i.obj,s);
}
TEST(Intersections,AggregatingIntersections) {
    RSphere s;
    RIntersection i1(1,&s);
    RIntersection i2(2,&s);
    vector<RIntersection> xs=RIntersection::intersections({i1,i2});
    ASSERT_EQ(xs.size(),2);
    EXPECT_FLOAT_EQ(xs[0].t,1);
    EXPECT_FLOAT_EQ(xs[1].t,2);
}

TEST(Intersections,TheHitWhenAllIntersectionsHavePositiveT) {
    RSphere s;
    RIntersection i1(1,&s);
    RIntersection i2(2,&s);
    vector<RIntersection> xs=RIntersection::intersections({i2,i1});
    RIntersection i=RIntersection::hit(xs);
    EXPECT_EQ(i,i1);
}
TEST(Intersections,HitNegativeT) {
    RSphere s;
    RIntersection i1(-1,&s);
    RIntersection i2(1,&s);
    vector<RIntersection> xs=RIntersection::intersections({i2,i1});
    RIntersection i=RIntersection::hit(xs);
    EXPECT_EQ(i,i2);
}
TEST(Intersections,HitAllNegativeT) {
    RSphere s;
    RIntersection i1(-2,&s);
    RIntersection i2(-1,&s);
    vector<RIntersection> xs=RIntersection::intersections({i2,i1});
    RIntersection i=RIntersection::hit(xs);
    EXPECT_EQ(i,RIntersection());
}
TEST(Intersections,HitLowestNonnegativeIntersection) {
    RSphere s;
    RIntersection i1(5,&s);
    RIntersection i2(7,&s);
    RIntersection i3(-3,&s);
    RIntersection i4(2,&s);

    vector<RIntersection> xs=RIntersection::intersections({i1,i2,i3,i4});
    RIntersection i=RIntersection::hit(xs);
    EXPECT_EQ(i,i4);
}
