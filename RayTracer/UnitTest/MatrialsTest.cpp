#include "UnitTest.h"

TEST(Material,DefaultMaterial) {
    RMaterial m;
    EXPECT_EQ(m.color,RColor(1,1,1));
    EXPECT_FLOAT_EQ(m.ambient,0.1);
    EXPECT_FLOAT_EQ(m.diffuse,0.9);
    EXPECT_FLOAT_EQ(m.specular,0.9);
    EXPECT_FLOAT_EQ(m.shininess,200.0);
}
TEST(Lighting,LightingWithEyeBetweenLightAndSurface) {
    RMaterial m;
    RPoint position;
    RVector eyev(0,0,-1);
    RVector normalv(0,0,-1);
    RPointLight light(RPoint(0,0,-10),RColor(1,1,1));
    RColor result=lighting(m,light,position,eyev,normalv);
    EXPECT_EQ(result,RColor(1.9,1.9,1.9));
}
TEST(Lighting,LightingWithEyeOppositeSurfaceLightOffset45) {
    RMaterial m;
    RPoint position;
    RVector eyev(0,0,-1);
    RVector normalv(0,0,-1);
    RPointLight light(RPoint(0,10,-10),RColor(1,1,1));
    RColor result=lighting(m,light,position,eyev,normalv);
    EXPECT_EQ(result,RColor(0.7364, 0.7364, 0.7364));
}
TEST(Lighting,LightingWithEyeInThePathOfTheReflectionVector) {
    RMaterial m;
    RPoint position;
    RVector eyev(0,-sqrt(2)/2,-sqrt(2)/2);
    RVector normalv(0,0,-1);
    RPointLight light(RPoint(0,10,-10),RColor(1,1,1));
    RColor result=lighting(m,light,position,eyev,normalv);
    cout<<result.r<<" "<<result.g<<" "<<result.b<<" "<<endl;
    EXPECT_EQ(result,RColor(1.63639, 1.63639, 1.63639));
}
TEST(Lighting,LightWithTheLightBehindTheSurface) {
    RMaterial m;
    RPoint position;
    RVector eyev(0,0,-1);
    RVector normalv(0,0,-1);
    RPointLight light(RPoint(0,0,10),RColor(1,1,1));
    RColor result=lighting(m,light,position,eyev,normalv);
    EXPECT_EQ(result,RColor(0.1, 0.1, 0.1));
}
