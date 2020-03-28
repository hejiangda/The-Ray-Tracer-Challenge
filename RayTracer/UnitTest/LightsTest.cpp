#include "UnitTest.h"

TEST(Light,PointLightHasPositionAndIntensity) {
    RColor intensity(1,1,1);
    RPoint position(0,0,0);
    RPointLight light(position,intensity);
    EXPECT_EQ(light.position,position);
    EXPECT_EQ(light.intensity,intensity);
}

