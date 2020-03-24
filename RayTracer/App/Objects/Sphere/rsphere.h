#ifndef RSPHERE_H
#define RSPHERE_H

#include "Tuple/rtuple.h"
#include "Objects/robject.h"
class RSphere:public RObject
{
public:
    RSphere();
    RPoint origin;
    float r;
private:
    static int cnt;
};

#endif // RSPHERE_H
