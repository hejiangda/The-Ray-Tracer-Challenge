#include "robject.h"

RObject::RObject()
{

}
bool RObject::operator==(const RObject& a)const {
    return a.type==type and a.id==id;
}
