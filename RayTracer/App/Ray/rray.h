#ifndef RRAY_H
#define RRAY_H

#include "../App/Tuple/rtuple.h"
#include "../App/Matrix/rmatrix.h"
class RRay
{
public:
    RRay(RPoint ori,RVector dir);
    RPoint origin;
    RVector direction;
    RPoint position(float t);
};

#endif // RRAY_H
