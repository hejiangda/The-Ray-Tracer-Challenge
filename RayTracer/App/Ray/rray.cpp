#include "rray.h"

RRay::RRay(RPoint ori,RVector dir):origin(ori),direction(dir){}

RPoint RRay::position(float t) {
    return origin+t*direction;
}
vector<RIntersection> RRay::intersect(RSphere s) {
    RVector sphere2Ray(origin-s.origin);
    float a=direction*direction;
    float b=2*direction*sphere2Ray;
    float c=sphere2Ray*sphere2Ray-1;
    float discriminant=b*b-4*a*c;
    if(discriminant<0)return {};
    float t1=(-b-sqrt(discriminant))/(2*a);
    float t2=(-b+sqrt(discriminant))/(2*a);
    RIntersection i1(t1,s),i2(t2,s);

    return {i1,i2};
}
