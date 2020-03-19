#ifndef RRAY_H
#define RRAY_H

#include "Tuple/rtuple.h"
#include "Matrix/rmatrix.h"
#include "Sphere/rsphere.h"
class RRay
{
public:
    RRay(RPoint ori,RVector dir);
    vector<float> intersect(RSphere s);
    RPoint origin;
    RVector direction;
    RPoint position(float t);
};

#endif // RRAY_H
