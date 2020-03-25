#include "rray.h"

RRay::RRay(RPoint ori,RVector dir):origin(ori),direction(dir){}

RPoint RRay::position(float t) {
    return origin+t*direction;
}
vector<RIntersection> RRay::intersect(RSphere& s) {
    RRay t=transform(s.transform.inverse());
    RVector sphere2Ray(t.origin-s.origin);
    float a=t.direction*t.direction;
    float b=2*t.direction*sphere2Ray;
    float c=sphere2Ray*sphere2Ray-1;
    float discriminant=b*b-4*a*c;
    if(discriminant<0)return {};
    float t1=(-b-sqrt(discriminant))/(2*a);
    float t2=(-b+sqrt(discriminant))/(2*a);
    RIntersection i1(t1,s),i2(t2,s);

    return {i1,i2};
}
RRay RRay::transform(RMatrix4 m) {
    RVector d=m*direction;
    RPoint o=m*origin;
    return RRay(o,d);
}
