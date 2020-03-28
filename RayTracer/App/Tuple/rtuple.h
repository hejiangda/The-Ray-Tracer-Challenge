#ifndef RTUPLE_H
#define RTUPLE_H
#include <cmath>
#include <vector>
using namespace std;
enum TupeType{POINT,VECTOR};
bool floatCmp(const float& a,const float& b);
class RTuple
{
public:
    RTuple(float x=0, float y=0, float z=0, float w=0);

    float x,y,z,w;
    TupeType type();
    bool operator==(const RTuple& )const;
    RTuple operator+(const RTuple& );
    RTuple operator-();
    RTuple operator*(const float& );
    friend RTuple operator*(const float& a,const RTuple& b);
    RTuple operator/(const float& );
    friend RTuple operator/(const float& a,const RTuple& b);
    float& operator[](int idx);
    const float& operator[](int idx)const;
};
class RVector:public RTuple
{
public:
    RVector(float x=0,float y=0,float z=0);
    RVector(RTuple b);
    RVector operator-(const RVector& );
    RVector operator-();
    float magnitude();
    RVector normalize();
    RVector operator*(const float& b) const;
    friend RVector operator*(const float& scal,const RVector b);
    float operator*(const RVector& b) const;
    RVector operator&(const RVector& b) const;
    RVector operator+(const RVector& b) const;
    RVector reflect(RVector& n);
};
class RPoint:public RTuple
{
public:
    RPoint(float x=0,float y=0,float z=0);
    RPoint(RTuple b);
    RVector operator-(const RPoint& );
    RPoint operator-(const RVector& );
    RPoint operator+(const RVector& );
    RPoint operator*(const float& ) const;
    friend RPoint operator*(const float& scal,const RPoint b);
};
class RColor
{
public:
    RColor(float r=0,float g=0,float b=0);
    float r,g,b;
    RColor operator+(const RColor& c);
    RColor operator-(const RColor& c);
    bool operator==(const RColor& c)const;
    RColor operator*(const float& c);
    friend RColor operator*(const float& c,const RColor d);
    RColor operator*(const RColor& c);
};

#endif // RTUPLE_H
