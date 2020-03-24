#include "rsphere.h"
int RSphere::cnt=0;
RSphere::RSphere():r(1.0)
{
    type=SPHERE;
    id=cnt++;
}
