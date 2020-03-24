#include "UnitTest.h"

TEST(Sphere,RayIntersectsSphere) {
    RRay r(RPoint(0,0,-5),RVector(0,0,1));
    RSphere s;
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),2);
    EXPECT_FLOAT_EQ(xs[0].t,4.0);
    EXPECT_FLOAT_EQ(xs[1].t,6.0);
}

TEST(Sphere,RayIntersectsSphereAtTangent) {
    RRay r(RPoint(0,1,-5),RVector(0,0,1));
    RSphere s;
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),2);
    EXPECT_FLOAT_EQ(xs[0].t,5.0);
    EXPECT_FLOAT_EQ(xs[1].t,5.0);
}
TEST(Sphere,RayMissesSphere) {
    RRay r(RPoint(0,2,-5),RVector(0,0,1));
    RSphere s;
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),0);
}
TEST(Sphere,RayOriginatesInsideSphere) {
    RRay r(RPoint(0,0,0),RVector(0,0,1));
    RSphere s;
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),2);
    EXPECT_FLOAT_EQ(xs[0].t,-1.0);
    EXPECT_FLOAT_EQ(xs[1].t,1.0);
}
TEST(Sphere,ShpereBehindRay) {
    RRay r(RPoint(0,0,5),RVector(0,0,1));
    RSphere s;
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),2);
    EXPECT_EQ(xs[0].obj,s);
    EXPECT_EQ(xs[1].obj,s);
}
