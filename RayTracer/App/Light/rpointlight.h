#ifndef RPOINTLIGHT_H
#define RPOINTLIGHT_H

#include "Tuple/rtuple.h"

class RPointLight
{
public:
    RPointLight();
    RPointLight(RPoint p,RColor i):intensity(i),position(p){};
    RColor intensity;
    RPoint position;
};

#endif // RPOINTLIGHT_H
