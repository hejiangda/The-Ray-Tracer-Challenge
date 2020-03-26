#include "rsphere.h"
int RSphere::cnt=0;
RSphere::RSphere():r(1.0)
{
    type=SPHERE;
    id=++cnt;
}
void RSphere::set_transform(RMatrix4 t) {
    transform=t;
}
RVector RSphere::normal_at(RPoint world_point) {
    RMatrix4 inv=transform.inverse();
    RPoint object_point=inv*world_point;
    RVector object_normal=object_point-RPoint();
    RVector world_normal=inv.transpose()*object_normal;
    world_normal.w=0;
    return world_normal.normalize();
}
