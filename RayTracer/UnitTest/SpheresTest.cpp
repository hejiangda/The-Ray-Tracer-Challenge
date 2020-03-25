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
TEST(Sphere,DefaultTransformation) {
    RSphere s;
    EXPECT_EQ(s.transform,RMatrix4());
}
TEST(Sphere,ChangingSphereTransformation) {
    RSphere s;
    RMatrix4 t;
    t.translation(2,3,4);
    s.set_transform(t);
    EXPECT_EQ(s.transform,t);
}
TEST(Sphere,IntersectingAScaledSphereWithARay) {
    RRay r(RPoint(0,0,-5),RVector(0,0,1));
    RSphere s;
    s.set_transform(RMatrix4().scale(2,2,2));
    vector<RIntersection> xs=r.intersect(s);
    ASSERT_EQ(xs.size(),2);
    EXPECT_EQ(xs[0].t,3);
    EXPECT_EQ(xs[1].t,7);
}
TEST(Sphere,IntersectingATranslatedSphereWithARay) {
    RRay r(RPoint(0,0,-5),RVector(0,0,1));
    RSphere s;
    s.set_transform(RMatrix4().translation(5,0,0));
    vector<RIntersection> xs=r.intersect(s);
    EXPECT_EQ(xs.size(),0);
}
