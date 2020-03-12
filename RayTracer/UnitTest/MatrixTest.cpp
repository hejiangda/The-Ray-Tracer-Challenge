#include "UnitTest.h"

TEST(Matrix,Matrix4x4) {
    RMatrix4 m({
                   1,2,3,4,
                   5.5,6.5,7.5,8.5,
                   9,10,11,12,
                   13.5,14.5,15.5,16.5
               });

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
    m[1][0]=1;m[1][1]=-2;m[1][2]=-7;
    m[2][0]=0;m[2][1]=1;m[2][2]=1;
    EXPECT_EQ(m[0][0],-3);
    EXPECT_EQ(m[1][1],-2);
    EXPECT_EQ(m[2][2],1);
}

TEST(Matrix,equal4) {
    RMatrix4 a;
    a[0][0]=1;a[0][1]=2;a[0][2]=3;a[0][3]=4;
    a[1][0]=5;a[1][1]=6;a[1][2]=7;a[1][3]=8;
    a[2][0]=9;a[2][1]=8;a[2][2]=7;a[2][3]=6;
    a[3][0]=5;a[3][1]=4;a[3][2]=3;a[3][3]=2;

    RMatrix4 b;
    b[0][0]=1;b[0][1]=2;b[0][2]=3;b[0][3]=4;
    b[1][0]=5;b[1][1]=6;b[1][2]=7;b[1][3]=8;
    b[2][0]=9;b[2][1]=8;b[2][2]=7;b[2][3]=6;
    b[3][0]=5;b[3][1]=4;b[3][2]=3;b[3][3]=2;

    EXPECT_EQ(a,b);

}
TEST(Matrix,notEqual4) {
    RMatrix4 a;
    a[0][0]=1;a[0][1]=2;a[0][2]=3;a[0][3]=4;
    a[1][0]=5;a[1][1]=6;a[1][2]=7;a[1][3]=8;
    a[2][0]=9;a[2][1]=8;a[2][2]=7;a[2][3]=6;
    a[3][0]=5;a[3][1]=4;a[3][2]=3;a[3][3]=2;

    RMatrix4 b;
    b[0][0]=2;b[0][1]=3;b[0][2]=4;b[0][3]=1;
    b[1][0]=6;b[1][1]=7;b[1][2]=8;b[1][3]=5;
    b[2][0]=8;b[2][1]=7;b[2][2]=6;b[2][3]=9;
    b[3][0]=4;b[3][1]=3;b[3][2]=2;b[3][3]=5;

    EXPECT_NE(a,b);
}
TEST(Matrix,equal3) {
    RMatrix3 a({
                   1,2,3,
                   4,5,6,
                   7,8,9
               });
    RMatrix3 b({
                   1,2,3,
                   4,5,6,
                   7,8,9
               });
    EXPECT_EQ(a,b);
}
TEST(Matrix,notEqual3) {
    RMatrix3 a({
                   1,2,3,
                   4,5,6,
                   7,8,9
               });
    RMatrix3 b({
                   0,2,3,
                   4,5,6,
                   7,8,9
               });
    EXPECT_NE(a,b);
}
TEST(Matrix,equal2) {
    RMatrix2 a({
                   1,2,3,4
               });
    RMatrix2 b({1,2,3,4});
    EXPECT_EQ(a,b);
}
TEST(Matrix,notEqual2) {
    RMatrix2 a({
                   1,2,3,4
               });
    RMatrix2 b({2,3,4,1});
    EXPECT_NE(a,b);
}
TEST(Matrix,MultiplyMatrix4x4) {
    RMatrix4 a;
    a[0][0]=1;a[0][1]=2;a[0][2]=3;a[0][3]=4;
    a[1][0]=5;a[1][1]=6;a[1][2]=7;a[1][3]=8;
    a[2][0]=9;a[2][1]=8;a[2][2]=7;a[2][3]=6;
    a[3][0]=5;a[3][1]=4;a[3][2]=3;a[3][3]=2;

    RMatrix4 b;
    b[0][0]=-2;b[0][1]=1;b[0][2]=2;b[0][3]=3;
    b[1][0]=3;b[1][1]=2;b[1][2]=1;b[1][3]=-1;
    b[2][0]=4;b[2][1]=3;b[2][2]=6;b[2][3]=5;
    b[3][0]=1;b[3][1]=2;b[3][2]=7;b[3][3]=8;

    RMatrix4 c;
    c[0][0]=20;c[0][1]=22;c[0][2]=50;c[0][3]=48;
    c[1][0]=44;c[1][1]=54;c[1][2]=114;c[1][3]=108;
    c[2][0]=40;c[2][1]=58;c[2][2]=110;c[2][3]=102;
    c[3][0]=16;c[3][1]=26;c[3][2]=46;c[3][3]=42;
    EXPECT_EQ(a*b,c);
    a.print();
    b.print();
    (a*b).print();
    c.print();
}
TEST(Matrix,MultiplyTuple) {
    RMatrix4 a;
    a[0][0]=1;a[0][1]=2;a[0][2]=3;a[0][3]=4;
    a[1][0]=2;a[1][1]=4;a[1][2]=4;a[1][3]=2;
    a[2][0]=8;a[2][1]=6;a[2][2]=4;a[2][3]=1;
    a[3][0]=0;a[3][1]=0;a[3][2]=0;a[3][3]=1;

    RTuple b(1,2,3,1);
    EXPECT_EQ(a*b,RTuple(18,24,33,1));
}
TEST(Matrix,identity) {
    RMatrix4 i;
    i.toIdentity();
    RMatrix4 m({
                   1,0,0,0,
                   0,1,0,0,
                   0,0,1,0,
                   0,0,0,1
               });
    EXPECT_EQ(i,m);
}
TEST(Matrix,multiplyAnIdentity) {
    RMatrix4 i;
    i.toIdentity();
    RMatrix4 a({
                   0,1,2,4,
                   1,2,4,8,
                   2,4,8,16,
                   4,8,16,32
               });
    EXPECT_EQ(i*a,a);
}
TEST(Matrix,Transpose) {
    RMatrix4 m({
                   0,9,3,0,
                   9,8,0,8,
                   1,8,5,3,
                   0,0,5,8
               });
    RMatrix4 t({
                   0,9,1,0,
                   9,8,8,0,
                   3,0,5,5,
                   0,8,3,8
               });
    EXPECT_EQ(t,m.transpose());
}
TEST(Matrix,TransposeIdentity) {
    RMatrix4 i;
    i.toIdentity();
    EXPECT_EQ(i,i.transpose());
}
TEST(Matrix,determinant) {
    RMatrix2 a({1,5,-3,2});
    EXPECT_EQ(a.determinant(),17);
}
TEST(Matrix,submatrix2) {
    RMatrix3 a({
                   1,5,0,
                   -3,2,7,
                   0,6,-3
               });
    RMatrix2 b({
                   -3,2,
                   0,6
               });
    EXPECT_EQ(b,a.submatrix(0,2));
}
TEST(Matrix,submatrix3) {
    RMatrix4 a({
                   -6,1,1,6,
                   -8,5,8,6,
                   -1,0,8,2,
                   -7,1,-1,1
               });
    RMatrix3 b({
                   -6,1,6,
                   -8,8,6,
                   -7,-1,1
               });
    EXPECT_EQ(a.submatrix(2,1),b);
}
TEST(Matrix,minor) {
    RMatrix3 a({
                   3,5,0,
                   2,-1,-7,
                   6,-1,5
               });
    RMatrix2 b=a.submatrix(1,0);
    EXPECT_EQ(b.determinant(),25);
    EXPECT_EQ(a.minor(1,0),25);
}
TEST(Matrix,cofactor) {
    RMatrix3 a({
                   3,5,0,
                   2,-1,-7,
                   6,-1,5
               });
    EXPECT_EQ(a.minor(0,0),-12);
    EXPECT_EQ(a.cofactor(0,0),-12);
    EXPECT_EQ(a.minor(1,0),25);
    EXPECT_EQ(a.cofactor(1,0),-25);
}
TEST(Matrix,determinant3) {
    RMatrix3 a({
                   1,2,6,
                   -5,8,-4,
                   2,6,4
               });
    EXPECT_EQ(a.cofactor(0,0),56);
    EXPECT_EQ(a.cofactor(0,1),12);
    EXPECT_EQ(a.cofactor(0,2),-46);
    EXPECT_EQ(a.determinant(),-196);
}
TEST(Matrix,determinant4) {
    RMatrix4 a({
                   -2,-8,3,5,
                   -3,1,7,3,
                   1,2,-9,6,
                   -6,7,7,-9
               });
    EXPECT_EQ(a.cofactor(0,0),690);
    EXPECT_EQ(a.cofactor(0,1),447);
    EXPECT_EQ(a.cofactor(0,2),210);
    EXPECT_EQ(a.cofactor(0,3),51);
    EXPECT_EQ(a.determinant(),-4071);

}
TEST(Matrix,invertible1) {
    RMatrix4 a({
                   6,4,4,4,
                   5,5,7,6,
                   4,-9,3,-7,
                   9,1,7,-6
               });
    EXPECT_EQ(a.determinant(),-2120);
    EXPECT_TRUE(a.canInv());
}
TEST(Matrix,invertible) {
    RMatrix4 a({
                   -4,2,-2,-3,
                   9,6,2,6,
                   0,-5,1,-5,
                   0,0,0,0
               });
    EXPECT_EQ(a.determinant(),0);
    EXPECT_FALSE(a.canInv());
}
TEST(Matrix,inverse1) {
    RMatrix4 a({
                   -5,2,6,-8,
                   1,-5,1,8,
                   7,7,-6,-7,
                   1,-3,7,4
               });
    RMatrix4 b=a.inverse();
    EXPECT_EQ(a.determinant(),532);
    EXPECT_EQ(a.cofactor(2,3),-160);
    EXPECT_TRUE(floatCmp(b[3][2],-160.0/532));
    EXPECT_TRUE(floatCmp(a.cofactor(3,2),105));
    EXPECT_TRUE(floatCmp(b[2][3],105.0/532));
    EXPECT_EQ(b,RMatrix4({
       0.21805 ,  0.45113 ,  0.24060 , -0.04511 ,
      -0.80827 , -1.45677 , -0.44361 ,  0.52068 ,
      -0.07895 , -0.22368 , -0.05263 ,  0.19737 ,
      -0.52256 , -0.81391 , -0.30075 ,  0.30639
                         }));

}
TEST(Matrix,inverse2) {
    RMatrix4 a({
                 8 , -5 ,  9 ,  2 ,
                 7 ,  5 ,  6 ,  1 ,
                -6 ,  0 ,  9 ,  6 ,
                -3 ,  0 , -9 , -4 ,
               });
    EXPECT_EQ(a.inverse(),RMatrix4({
     -0.15385,-0.15385,-0.28205,-0.53846,
     -0.07692, 0.12308, 0.02564, 0.03077,
      0.35897, 0.35897, 0.43590, 0.92308,
     -0.69231,-0.69231,-0.76923,-1.92308,
                                   }));

}
TEST(Matrix,inverse3) {
    RMatrix4 a({
      9 ,  3 ,  0 ,  9 ,
     -5 , -2 , -6 , -3 ,
     -4 ,  9 ,  6 ,  4 ,
     -7 ,  6 ,  6 ,  2 ,
               });
    EXPECT_EQ(a.inverse(),RMatrix4({
    -0.04074,-0.07778, 0.14444,-0.22222,
    -0.07778, 0.03333, 0.36667,-0.33333,
    -0.02901,-0.14630,-0.10926, 0.12963,
     0.17778, 0.06667,-0.26667, 0.33333,
                                   }));

}
TEST(Matrix,multiplyInverse) {
    RMatrix4 a({
          3 , -9 ,  7 ,  3 ,
          3 , -8 ,  2 , -9 ,
         -4 ,  4 ,  4 ,  1 ,
         -6 ,  5 , -1 ,  1 ,
               });
    RMatrix4 b({
          8 ,  2 ,  2 ,  2 ,
          3 , -1 ,  7 ,  0 ,
          7 ,  0 ,  5 ,  4 ,
          6 , -2 ,  0 ,  5 ,
               });
    auto c=a*b;
    EXPECT_EQ(c*b.inverse(),a);
}
