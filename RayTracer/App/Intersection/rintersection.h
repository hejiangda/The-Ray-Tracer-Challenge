#ifndef RINTERSECTION_H
#define RINTERSECTION_H

#include "Objects/robject.h"
#include <vector>
#include <algorithm>

using namespace std;
class RIntersection
{
public:
    RIntersection();
    RIntersection(float t,RObject o);
    float t;
    RObject obj;

    static vector<RIntersection> intersections(vector<RIntersection> v);
    bool operator==(const RIntersection& a)const;
    bool operator!=(const RIntersection& a)const {
        return !operator==(a);
    };
    bool operator<(const RIntersection& a)const;
    static RIntersection hit(vector<RIntersection>& v);
};

#endif // RINTERSECTION_H
