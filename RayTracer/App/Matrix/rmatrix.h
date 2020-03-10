#ifndef RMATRIX_H
#define RMATRIX_H
#include <vector>
#include <../App/Tuple/rtuple.h>
using namespace std;
class RMatrix3;
class RMatrix4
{
public:
    RMatrix4(vector<float>m={});
    float data[4][4];
    float* operator[](int idx);
    const float* operator[](int idx) const;
    bool operator==(const RMatrix4& b)const;
    bool operator!=(const RMatrix4& b)const;
    RMatrix4 operator*(const RMatrix4& b);
    RTuple operator*(const RTuple& b);
    void toIdentity();
    RMatrix4 transpose();
    RMatrix3 submatrix(int row,int col);
    float minor(int row,int col);
    float cofactor(int row,int col);
    float determinant();
    bool canInv();
    RMatrix4 inverse();
};
class RMatrix2
{
public:
    RMatrix2(vector<float>m={});
    float data[2][2];
    float* operator[](int idx);
    const float* operator[](int idx) const;
    bool operator!=(const RMatrix2& b)const;
    bool operator==(const RMatrix2& b)const;
    float determinant();
};
class RMatrix3
{
public:
    RMatrix3(vector<float>m={});
    float data[3][3];
    float* operator[](int idx);
    const float* operator[](int idx) const;
    bool operator==(const RMatrix3& b)const;
    bool operator!=(const RMatrix3& b)const;
    RMatrix2 submatrix(int row,int col);
    float minor(int row,int col);
    float cofactor(int row,int col);
    float determinant();
};
#endif // RMATRIX_H
