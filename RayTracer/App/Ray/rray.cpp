#include "rray.h"

RRay::RRay(RPoint ori,RVector dir):origin(ori),direction(dir){}

RPoint RRay::position(float t) {
    return origin+t*direction;
}
vector<float> RRay::intersect(RSphere s) {
    RVector sphere2Ray(origin-s.origin);
    float a=direction*direction;
    float b=2*direction*sphere2Ray;
    float c=sphere2Ray*sphere2Ray-1;
    float discriminant=b*b-4*a*c;
    if(discriminant<0)return {};
    float t1=(-b-sqrt(discriminant)/(2*a))+origin.z;
    float t2=(-b+sqrt(discriminant)/(2*a))+origin.z;
    return {t1,t2};
}
