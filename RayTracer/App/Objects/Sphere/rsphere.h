#ifndef RSPHERE_H
#define RSPHERE_H

#include "Tuple/rtuple.h"
#include "Objects/robject.h"
#include "Matrix/rmatrix.h"
#include "Light/rmaterial.h"
class RSphere:public RObject
{
public:
    RSphere();
    RPoint origin;
    float r;
    RMatrix4 transform;
    RMaterial material;
    void set_transform(RMatrix4 t);
    RVector normal_at(RPoint b);

private:
    static int cnt;
};

#endif // RSPHERE_H
