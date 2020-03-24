#ifndef RINTERSECTION_H
#define RINTERSECTION_H

#include "Objects/robject.h"
#include <vector>


using namespace std;
class RIntersection
{
public:
    RIntersection(float t,RObject o);
    float t;
    RObject obj;

    static vector<RIntersection> intersections(vector<RIntersection> v);
    bool operator==(const RIntersection& a)const;
};

#endif // RINTERSECTION_H
