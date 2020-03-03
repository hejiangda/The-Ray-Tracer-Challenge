#include "rtuple.h"

RTuple::RTuple(float x, float y, float z,float w):
    x(x),y(y),z(z),w(w)
{

}

TupeType RTuple::type() {
    return w==1.0?POINT:VECTOR;
}
bool floatCmp(const float& a,const float& b) {
    const float EPSILON=1E-5;
    if(std::fabs(a-b)<EPSILON)return true;
    return false;
}
bool RTuple::operator==(const RTuple& b)const {
    return (floatCmp(x,b.x) and floatCmp(y,b.y) and floatCmp(z,b.z) and floatCmp(w,b.w));
}
RTuple RTuple::operator+(const RTuple& b) {
    return RTuple(x+b.x,y+b.y,z+b.z,w+b.w);
}
RTuple RTuple::operator-() {
    return RTuple(-x,-y,-z,-w);
}
RTuple RTuple::operator*(const float& scal) {
    return RTuple(x*scal,y*scal,z*scal,w*scal);
}
RTuple operator*(const float& scal,const RTuple& b) {
    return RTuple(b.x*scal,b.y*scal,b.z*scal,b.w*scal);
}
RTuple RTuple::operator/(const float& scal) {
    return RTuple(x/scal,y/scal,z/scal,w/scal);
}
RTuple operator/(const float& scal,const RTuple& b) {
    return RTuple(b.x/scal,b.y/scal,b.z/scal,b.w/scal);
}
RPoint::RPoint(float xx,float yy,float zz)
{
    x=xx;y=yy;z=zz;
    w=1;
}
RPoint::RPoint(RTuple b) {
    x=b.x;y=b.y;z=b.z;w=1;
}
RVector RPoint::operator-(const RPoint& b) {
    return RVector(x-b.x,y-b.y,z-b.z);
}
RPoint RPoint::operator-(const RVector& b) {
    return RPoint(x-b.x,y-b.y,z-b.z);
}
RPoint RPoint::operator+(const RVector& b) {
    return RPoint(x+b.x,y+b.y,z+b.z);
}
RVector::RVector(float xx,float yy,float zz)
{
    x=xx;y=yy;z=zz;
    w=0;
}
RVector::RVector(RTuple b) {
    x=b.x;y=b.y;z=b.z;w=0;
}
RVector RVector::operator-(const RVector& b) {
    return RVector(x-b.x,y-b.y,z-b.z);
}
float RVector::magnitude() {
    return std::sqrt(x*x+y*y+z*z);
}
RVector RVector::normalize() {
    float m=magnitude();
    return RVector(x/m,y/m,z/m);
}
float RVector::operator*(const RVector& b) const {
    return x*b.x+y*b.y+z*b.z;
}
RVector RVector::operator&(const RVector& b) const {
    return RVector(y*b.z-z*b.y,
                   z*b.x-x*b.z,
                   x*b.y-y*b.x
                );
}
RVector RVector::operator+(const RVector &b) const {
    return RVector(x+b.x,y+b.y,z+b.z);
}
