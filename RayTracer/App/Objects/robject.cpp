#include "robject.h"

RObject::RObject():id(-1),type(SPHERE)
{

}
bool RObject::operator==(const RObject& a)const {
    return a.type==type and a.id==id;
}
