#include "rmatrix.h"

RMatrix4::RMatrix4(vector<float>m)
{
    int sz=m.size();
    float* p=data[0];
    int i=0;
    for(;i<16 and i<sz;i++) {
        *(p++)=m[i];
    }
    while(i<16) {
        *(p++)=0;
        i++;
    }
}
float* RMatrix4::operator[](int idx) {
    if(idx>=4 or idx<0)idx=0;
    return data[idx];
}
const float* RMatrix4::operator[](int idx)const {
    if(idx>=4 or idx<0)idx=0;
    return data[idx];
}
bool RMatrix4::operator==(const RMatrix4& b)const {
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        if(!floatCmp(data[i][j],b[i][j]))return false;
    }
    return true;
}
bool RMatrix4::operator!=(const RMatrix4& b)const {
    return !operator==(b);
}
RMatrix4 RMatrix4::operator*(const RMatrix4& b) {
    RMatrix4 ret;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        for(int h=0;h<4;h++) {
            ret[i][j]+=data[i][h]*b[h][j];
        }
    }
    return ret;
}
RTuple RMatrix4::operator*(const RTuple& b) {
    RTuple ret;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        ret[i]+=data[i][j]*b[j];
    }
    return ret;
}
void RMatrix4::toIdentity() {
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        if(i==j)data[i][j]=1;
        else data[i][j]=0;
    }
}
RMatrix4 RMatrix4::transpose() {
    RMatrix4 ret;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        ret[j][i]=data[i][j];
    }
    return ret;
}
RMatrix3 RMatrix4::submatrix(int row,int col) {
    RMatrix3 ret;
    int ii=0,jj=0;
    for(int i=0;i<4;i++){
        if(i==row)continue;
        jj=0;
        for(int j=0;j<4;j++) {
            if(j==col)continue;
            ret[ii][jj]=data[i][j];
            jj++;
        }
        ii++;
    }
    return ret;
}
float RMatrix4::minor(int row,int col) {
    return submatrix(row,col).determinant();
}
float RMatrix4::cofactor(int row,int col) {
    if((row+col)&1) return -minor(row,col);
    return minor(row,col);
}
float RMatrix4::determinant() {
    float ret=0;
    for(int i=0;i<4;i++) {
        ret+=data[0][i]*cofactor(0,i);
    }
    return ret;
}
bool RMatrix4::canInv() {
    if(floatCmp(determinant(),0))return false;
    return true;
}
RMatrix4 RMatrix4::inverse() {
    RMatrix4 ret;
    if(!canInv())return ret;
    float det=determinant();
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) {
        ret[j][i]=cofactor(i,j)/det;
    }
    return ret;
}
RMatrix2::RMatrix2(vector<float>m)
{
    int sz=m.size();
    float* p=data[0];
    int i=0;
    for(;i<4 and i<sz;i++) {
        *(p++)=m[i];
    }
    while(i<4) {
        *(p++)=0;
        i++;
    }
}
float* RMatrix2::operator[](int idx) {
    if(idx>=2 or idx<0)idx=0;
    return data[idx];
}
const float* RMatrix2::operator[](int idx)const {
    if(idx>=2 or idx<0)idx=0;
    return data[idx];
}
bool RMatrix2::operator==(const RMatrix2& b)const {
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) {
        if(data[i][j]!=b[i][j])return false;
    }
    return true;
}
bool RMatrix2::operator!=(const RMatrix2& b)const {
    return !operator==(b);
}
float RMatrix2::determinant() {
    return data[0][0]*data[1][1]-data[0][1]*data[1][0];
}
RMatrix3::RMatrix3(vector<float>m)
{
    int sz=m.size();
    float* p=data[0];
    int i=0;
    for(;i<9 and i<sz;i++) {
        *(p++)=m[i];
    }
    while(i<9) {
        *(p++)=0;
        i++;
    }
}
float* RMatrix3::operator[](int idx) {
    if(idx>=3 or idx<0)idx=0;
    return data[idx];
}
const float* RMatrix3::operator[](int idx)const {
    if(idx>=3 or idx<0)idx=0;
    return data[idx];
}
bool RMatrix3::operator==(const RMatrix3& b)const {
    for(int i=0;i<3;i++)for(int j=0;j<3;j++) {
        if(data[i][j]!=b[i][j])return false;
    }
    return true;
}
bool RMatrix3::operator!=(const RMatrix3& b)const {
    return !operator==(b);
}
RMatrix2 RMatrix3::submatrix(int row,int col) {
    RMatrix2 ret;
    int ii=0,jj=0;
    for(int i=0;i<3;i++){
        if(i==row)continue;
        jj=0;
        for(int j=0;j<3;j++) {
            if(j==col)continue;
            ret[ii][jj]=data[i][j];
            jj++;
        }
        ii++;
    }
    return ret;
}
float RMatrix3::minor(int row,int col) {
    return submatrix(row,col).determinant();
}
float RMatrix3::cofactor(int row,int col) {
    float m=minor(row,col);
    if((row+col)&1)return -m;
    return m;
}
float RMatrix3::determinant() {
    float ret=0;
    for(int i=0;i<3;i++) {
        ret+=data[0][i]*cofactor(0,i);
    }
    return ret;
}
