#ifndef RTUPLE_H
#define RTUPLE_H
#include <cmath>

enum TupeType{POINT,VECTOR};
class RTuple
{
public:

    RTuple(float x=0, float y=0, float z=0, float w=1);
    float x,y,z,w;
    TupeType type();
    bool operator==(const RTuple& )const;
    RTuple operator+(const RTuple& );
    RTuple operator-();
    RTuple operator*(const float& );
    friend RTuple operator*(const float& a,const RTuple& b);
    RTuple operator/(const float& );
    friend RTuple operator/(const float& a,const RTuple& b);
private:

    bool floatCmp(const float& a,const float& b)const;
};
class RVector:public RTuple
{
public:
    RVector(float x=0,float y=0,float z=0);
    RVector operator-(const RVector& );
    float magnitude()const;
    friend float magnitude(const RVector& v);
};
class RPoint:public RTuple
{
public:
    RPoint(float x=0,float y=0,float z=0);
    RVector operator-(const RPoint& );
    RPoint operator-(const RVector& );
};


#endif // RTUPLE_H
