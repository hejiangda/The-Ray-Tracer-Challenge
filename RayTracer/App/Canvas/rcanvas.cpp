#include "rcanvas.h"

RCanvas::RCanvas(int w,int h):width(w),height(h)
{
    data.resize(width);
    for(auto& x:data) {
        x.resize(height);
    }
}
RColor RCanvas::at(int row,int col) {
    return data[row][col];
}
bool RCanvas::write(int row,int col,RColor c) {
    if(row>=width or col>=height)return false;
    data[row][col]=c;
    return true;
}
