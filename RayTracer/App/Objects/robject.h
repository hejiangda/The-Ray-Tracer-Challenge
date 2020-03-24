#ifndef ROBJECT_H
#define ROBJECT_H


class RObject
{
public:
    RObject();
    int type;
    int id;
    enum{
        SPHERE
    };
    bool operator==(const RObject& a)const;
};

#endif // ROBJECT_H
