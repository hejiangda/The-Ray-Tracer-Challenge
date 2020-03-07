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

TEST(Canvas,PPMheader) {
    RCanvas c(5,3);
    QString ppm=c.to_ppm();
    QStringList list = ppm.split('\n', QString::SkipEmptyParts);
    ASSERT_EQ(list.at(0),QString("P3"));
    ASSERT_EQ(list.at(1),QString("5 3"));
    ASSERT_EQ(list.at(2),QString("255"));
}
TEST(Canvas,Data2PPM) {
    RCanvas c(5,3);
    c.write(0,0,RColor(1.5,0,0));
    c.write(2,1,RColor(0,0.5,0));
    c.write(4,2,RColor(-0.5,0,1));
    QStringList list = c.to_ppm().split('\n', QString::SkipEmptyParts);
    EXPECT_STREQ(list.at(3).toStdString().c_str(),"255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    EXPECT_STREQ(list.at(4).toStdString().c_str(),"0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
    EXPECT_STREQ(list.at(5).toStdString().c_str(),"0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}
TEST(Canvas,SplitLongLinesPPM) {
    RCanvas c(10,2);
    RColor color(1,.8,.6);
    for(int i=0;i<c.width;i++) {
        for(int j=0;j<c.height;j++) {
            c.write(i,j,color);
        }
    }
    QStringList list=c.to_ppm().split('\n', QString::SkipEmptyParts);
    EXPECT_STREQ(list.at(3).toStdString().c_str(),"255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    EXPECT_STREQ(list.at(4).toStdString().c_str(),"153 255 204 153 255 204 153 255 204 153 255 204 153");
    EXPECT_STREQ(list.at(5).toStdString().c_str(),"255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    EXPECT_STREQ(list.at(6).toStdString().c_str(),"153 255 204 153 255 204 153 255 204 153 255 204 153");

}
TEST(Canvas,PPMTerminatedByNewLine) {
    RCanvas c(5,3);
    QString ppm=c.to_ppm();
    EXPECT_EQ(ppm.back(),'\n');
}
