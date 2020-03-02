#include "rtuple.h"

RTuple::RTuple(float x, float y, float z,float w):
    x(x),y(y),z(z),w(w)
{

}

TupeType RTuple::type() {
    return w==1.0?POINT:VECTOR;
}
bool RTuple::operator==(const RTuple& b)const {
    return (x==b.x and y==b.y and z==b.z and w==b.w);
}
RPoint::RPoint(float xx,float yy,float zz)
{
    x=xx;y=yy;z=zz;
    w=1;
}
RVector::RVector(float xx,float yy,float zz)
{
    x=xx;y=yy;z=zz;
    w=0;
}
