#include "UnitTest.h"

TEST(Matrix,Matrix4x4) {
    RMatrix4 m;
    m[0][0]=1;m[0][1]=2;m[0][2]=3;m[0][3]=4;
    m[1][0]=5.5;m[1][1]=6.5;m[1][2]=7.5;m[1][3]=8.5;
    m[2][0]=9;m[2][1]=10;m[2][2]=11;m[2][3]=12;
    m[3][0]=13.5;m[3][1]=14.5;m[3][2]=15.5;m[3][3]=16.5;

    EXPECT_EQ(m[0][0],1);
    EXPECT_EQ(m[0][3],4);
    EXPECT_EQ(m[1][0],5.5);
    EXPECT_EQ(m[1][2],7.5);
    EXPECT_EQ(m[2][2],11);
    EXPECT_EQ(m[3][0],13.5);
    EXPECT_EQ(m[3][2],15.5);
}

TEST(Matrix,Matrix2x2) {
    RMatrix2 m;
    m[0][0]=-3;m[0][1]=5;
    m[1][0]=1;m[1][1]=-2;
    EXPECT_EQ(m[0][0],-3);
    EXPECT_EQ(m[0][1],5);
    EXPECT_EQ(m[1][0],1);
    EXPECT_EQ(m[1][1],-2);
}

TEST(Matrix,Matrix3x3) {
    RMatrix3 m;
    m[0][0]=-3;m[0][1]=5;m[0][2]=0;
    m[0][0]=1;m[0][1]=-2;m[0][2]=-7;
    m[0][0]=0;m[0][1]=1;m[0][2]=1;
    EXPECT_EQ(m[0][0],-3);
    EXPECT_EQ(m[1][1],-2);
    EXPECT_EQ(m[2][2],1);
}
