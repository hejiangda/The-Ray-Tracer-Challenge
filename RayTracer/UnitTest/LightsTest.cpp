#include "UnitTest.h"

TEST(Light,PointLightHasPositionAndIntensity) {
    RColor intensity(1,1,1);
    RPoint position(0,0,0);
    RPointLight light(position,intensity);
    EXPECTED_EQ(light.position,position);
    EXPECTED_EQ(light.intensity,intensity);
}

