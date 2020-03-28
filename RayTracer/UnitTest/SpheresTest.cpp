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
    EXPECT_EQ(*xs[0].obj,s);
    EXPECT_EQ(*xs[1].obj,s);
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
TEST(Sphere,NormalOnASphereAtXAxis) {
    RSphere s;
    RVector n=s.normal_at(RPoint(1,0,0));
    EXPECT_EQ(n,RVector(1,0,0));

}
TEST(Sphere,NormalOnASphereAtYAxis) {
    RSphere s;
    RVector n=s.normal_at(RPoint(0,1,0));
    EXPECT_EQ(n,RVector(0,1,0));

}
TEST(Sphere,NormalOnASphereAtZAxis) {
    RSphere s;
    RVector n=s.normal_at(RPoint(0,0,1));
    EXPECT_EQ(n,RVector(0,0,1));

}
TEST(Sphere,NormalOnASphereAtNonAxis) {
    RSphere s;
    RVector n=s.normal_at(RPoint(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3));
    EXPECT_EQ(n,RVector(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3));

}
TEST(Sphere,NormalIsNormalized) {
    RSphere s;
    RVector n=s.normal_at(RPoint(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3));
    EXPECT_EQ(n,n.normalize());

}
TEST(Sphere,ComputingTheNormalOnATranslatedSphere) {
    RSphere s;
    s.set_transform(RMatrix4().translation(0,1,0));
    RVector n=s.normal_at(RPoint(0,1.70711,-0.70711));
    EXPECT_EQ(n,RVector(0,0.70711,-0.70711));
}
TEST(Sphere,ComputingTheNormalOnATranslatedSphere1) {
    RSphere s;
    RMatrix4 m;
    m.scale(1,0.5,1).rotation_z(M_PI/5);
    s.set_transform(m);
    RVector n=s.normal_at(RPoint(0,sqrt(2)/2,-sqrt(2)/2));
    EXPECT_EQ(n,RVector(0,0.97014,-0.24254));
}
TEST(Sphere,SphereDefaultMaterial) {
    RSphere s;
    RMaterial m=s.material;
    EXPECT_EQ(m,RMaterial());
}
TEST(Sphere,AssignMaterialToSphere) {
    RSphere s;
    RMaterial m;
    m.ambient=1;
    s.material=m;
    EXPECT_EQ(s.material,m);
}
