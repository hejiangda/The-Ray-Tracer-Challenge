#ifndef RMATERIAL_H
#define RMATERIAL_H

#include "Tuple/rtuple.h"
#include "rpointlight.h"
class RMaterial
{
public:
    RMaterial();
    RColor color;
    float ambient;
    float diffuse;
    float specular;
    float shininess;
    bool operator==(const RMaterial& m)const;
};
RColor lighting(RMaterial m,RPointLight light,RPoint point,RVector eyev,RVector normalv);
#endif // RMATERIAL_H
