#include "UnitTest.h"

TEST(World,CreateWorld) {
    RWorld w;
    EXPECT_EQ(w.objects.size(),0);
    EXPECT_EQ(w.lights.size(),0);
}
TEST(World,DefaultWorld) {
    RPointLight light(RPoint(-10,10,-10),RColor(1,1,1));
    RSphere s1;
    s1.material.color=RColor(0.8,1.0,0.6);
    s1.material.diffuse=0.7;
    s1.material.specular=0.2;
    RSphere s2;
    s2.transform=RMatrix4().scale(.5,.5,.5);
    RWorld w;
    w.default_world();
    EXPECT_EQ(w.light,light);
    ASSERT_EQ(w.objects.size(),2);
    EXPECT_NE(w.objects.find(s1),w.objects.end());
    EXPECT_NE(w.objects.find(s2),w.objects.end());
}
TEST(World,IntersectAWorldWithARay) {
    RWorld w;
    RRay r(RPoint(0,0,-5),RVector(0,0,1));
    vector<RIntersection> xs=r.intersect_world(w);
    ASSERT_FLOAT_EQ(xs.size(),4);
    EXPECT_FLOAT_EQ(xs[0].t,4);
    EXPECT_FLOAT_EQ(xs[1].t,4.5);
    EXPECT_FLOAT_EQ(xs[2].t,5.5);
    EXPECT_FLOAT_EQ(xs[3].t,6);
}
TEST(World,PrecomputingTheStateOfAnIntersection) {
    RRay r(RPoint(0,0,-5),RVector(0,0,1));
    RSphere shape;
    RIntersection i(4,&shape);
    RPreComputation comps(i,r);
    EXPECT_FLOAT_EQ(comps.t,i.t);
    EXPECT_EQ(comps.object,i.object);
    EXPECT_EQ(comps.point,RPoint(0,0,-1));
    EXPECT_EQ(comps.eyev,RVector(0,0,-1));
    EXPECT_EQ(comps.normalv,RVector(0,0,-1));
}
