#ifndef RCANVAS_H
#define RCANVAS_H
#include <../App/Tuple/rtuple.h>
#include <vector>
class RCanvas
{
public:
    RCanvas(int w,int h);
    int width,height;
    std::vector<std::vector<RColor>> data;
    RColor at(int row,int col);
    bool write(int row,int col,RColor c);
};

#endif // RCANVAS_H
