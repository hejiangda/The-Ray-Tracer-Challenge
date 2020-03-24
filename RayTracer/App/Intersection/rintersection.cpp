#include "rintersection.h"

RIntersection::RIntersection(float t,RObject o):t(t),obj(o)
{

}
vector<RIntersection> RIntersection::intersections(vector<RIntersection> v) {
    return v;
}
bool RIntersection::operator==(const RIntersection& a)const {
    return t==a.t and obj==a.obj;
}
