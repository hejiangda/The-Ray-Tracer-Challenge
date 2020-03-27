#include "UnitTest.h"

TEST(Material,DefaultMaterial) {
    RMaterial m;
    EXPECTED_EQ(m.color,RColor(1,1,1));
    EXPECTED_FLOAT_EQ(m.ambient,0.1);
    EXPECTED_FLOAT_EQ(m.diffuse,0.9);
    EXPECTED_FLOAT_EQ(m.specular,0.9);
    EXPECTED_FLOAT_EQ(m.shininess,200.0);
}
