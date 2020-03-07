#include "rcanvas.h"

RCanvas::RCanvas(int w,int h):width(w),height(h)
{
    data.resize(height);
    for(auto& x:data) {
        x.resize(width);
        for(auto& y:x)y=0;
    }
}
RColor RCanvas::at(int col,int row) {
    return data[row][col];
}
bool RCanvas::write(int col,int row,RColor c) {
    if(row>=height or col>=width or row<0 or col <0)return false;
    data[row][col]=c;
    return true;
}
QString RCanvas::to_ppm() {
    QString ret;
    ret.push_back(QString("P3\n"));
    ret.push_back(QString("%1 %2\n").arg(width).arg(height));
    ret.push_back(QString("255\n"));
    for(int i=0;i<height;i++) {
        QString tmp=QString("%1 %2 %3").arg(color2draw(data[i][0].r,255)).arg(color2draw(data[i][0].g,255)).arg(color2draw(data[i][0].b,255));
        ret.push_back(tmp);
        int sz=tmp.length();
        for(int j=1;j<width;j++) {
            for(int k=0;k<3;k++) {
                QString tmp1;
                switch (k) {
                    case 0:tmp1=QString(" %1").arg(color2draw(data[i][j].r,255));
                        break;
                    case 1:tmp1=QString(" %1").arg(color2draw(data[i][j].g,255));
                        break;
                    case 2:tmp1=QString(" %1").arg(color2draw(data[i][j].b,255));
                        break;
                }
                if(sz+tmp1.length()>=70) {
                    switch (k) {
                        case 0:tmp1=QString("%1").arg(color2draw(data[i][j].r,255));
                            break;
                        case 1:tmp1=QString("%1").arg(color2draw(data[i][j].g,255));
                            break;
                        case 2:tmp1=QString("%1").arg(color2draw(data[i][j].b,255));
                            break;
                    }
                    ret.push_back('\n');
                    sz=0;
                }
                sz+=tmp1.length();
                ret.push_back(tmp1);
            }
        }
        ret.push_back('\n');
    }
    return ret;
}
int RCanvas::color2draw(float x,int maxn) {
    if(x<0)x=0;
    if(x>1)x=1;

    return x*maxn+0.5;
}
