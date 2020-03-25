#include "rsphere.h"
int RSphere::cnt=0;
RSphere::RSphere():r(1.0)
{
    type=SPHERE;
    id=cnt++;
}
void RSphere::set_transform(RMatrix4 t) {
    transform=t;
}
