#include "rintersection.h"
RIntersection::RIntersection():t(0),obj(nullptr){};
RIntersection::RIntersection(float t,RObject* o):t(t),obj(o)
{

}
bool RIntersection::operator<(const RIntersection& a)const {
    return t<a.t;
}
vector<RIntersection> RIntersection::intersections(vector<RIntersection> v) {
    sort(v.begin(),v.end());
    return v;
}
bool RIntersection::operator==(const RIntersection& a)const {
    if(obj==nullptr)
        return t==a.t and obj==a.obj;
    return t==a.t and *obj==*a.obj;
}
RIntersection RIntersection::hit(vector<RIntersection>& v) {
    for(auto& x:v) {
        if(x.t<0)continue;
        if(x.t>=0)return x;
    }
    return RIntersection();
}
