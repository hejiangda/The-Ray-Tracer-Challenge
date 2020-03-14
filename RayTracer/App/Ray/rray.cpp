#include "rray.h"

RRay::RRay(RPoint ori,RVector dir):origin(ori),direction(dir){}

RPoint RRay::position(float t) {
    return origin+t*direction;
}
