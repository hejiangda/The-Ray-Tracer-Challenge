#include "UnitTest.h"

TEST(Canvas,Create) {
    RCanvas c(10,20);
    ASSERT_EQ(c.width,10);
    ASSERT_EQ(c.height,20);
    for(int i=0;i<10;i++) {
        for(int j=0;j<20;j++) {
            ASSERT_EQ(c.at(i,j),RColor(0,0,0));
        }
    }
}

TEST(Canvas,Write) {
    RCanvas c(10,20);
    RColor red(1,0,0);
    c.write(2,3,red);
    ASSERT_EQ(c.at(2,3),red);
}

//TEST(Canvas,PPMheader) {

//}
