#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

struct projectile {
    RPoint position;
    RVector velocity;
    projectile(RPoint p,RVector v):position(p),velocity(v){}
};
struct environment {
    RVector gravity;
    RVector wind;
    environment(RVector g,RVector w):gravity(g),wind(w){}
};
projectile RTick(projectile p,environment e) {
    RPoint position=p.position+p.velocity;
    RVector velocity=(p.velocity+e.gravity+e.wind);
    return projectile(position,velocity);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/* projectile */
//    projectile proj(RPoint(0,1,0),RVector(1,1.8,0).normalize()*11.25);
//    environment env(RVector(0,-0.1,0),RVector(-0.01,0,0));
//    int tick=0;
//    RCanvas c(900,550);
//    RColor red(1,0,0);
//    while(proj.position.y>0) {
//        proj=RTick(proj,env);
//        qDebug()<<"Tick "<<++tick<<":";
//        qDebug()<<proj.position.x<<" "<<proj.position.y<<" "<<proj.position.z;
//        c.write(proj.position.x,550-proj.position.y,red);
//    }
//    QString ppm=c.to_ppm();

//    QFile file("projectile.ppm");
//    if(!file.open(QIODevice::ReadWrite)) {

//    }
//    file.write(ppm.toStdString().c_str(),ppm.length());


/* clock */
//    RCanvas clock(400,400);
//    RColor white(1,1,1);
//    clock.write(200,200,white);
//    RPoint p(0,1,0);

//    for(int i=0;i<12;i++) {
//        RMatrix4 rotScal;
//        rotScal.translation(200,200,0).scale(150,150,0).rotation_z((M_PI*i)/6);
//        RPoint tmp=rotScal*p;
//        clock.write(tmp.x,tmp.y,white);
//        qDebug()<<tmp.x<<" "<<tmp.y;
//    }
//    QString clockPpm=clock.to_ppm();
//    QFile file("clock.ppm");
//    if(!file.open(QIODevice::ReadWrite)) {

//    }
//    file.write(clockPpm.toStdString().c_str(),clockPpm.length());


/* ray cast a sphere */
//    RPoint ray_origin(0,0,-5);
//    RPoint wall(0,0,10);
//    const float wall_size=7.0;
//    const int canvas_pixels=400;
//    const float pixel_size=wall_size/canvas_pixels;
//    const float half=wall_size/2;

//    RCanvas canvas(canvas_pixels,canvas_pixels);
//    RColor color(1,0,0);
//    RSphere shape,tmp1;

//    qDebug()<<shape.id;
////    qDebug()<<RIntersection().obj.id;
//    for(int y=0;y<canvas_pixels;y++) {
//        float world_y=half-pixel_size*y;
//        for(int x=0;x<canvas_pixels;x++) {
//            float world_x=-half+pixel_size*x;
//            RPoint position(world_x,world_y,wall.z);
//            RRay r(ray_origin,RVector(position-ray_origin));
//            vector<RIntersection> xs=r.intersect(shape);
//            RIntersection tmp=RIntersection::hit(xs);
//            if(tmp!=RIntersection()) {
//                canvas.write(x,y,color);
//            }
//        }
//    }
//    QString sphere=canvas.to_ppm();
//    QFile file("sphere.ppm");
//    if(!file.open(QIODevice::ReadWrite)) {

//    }
//    file.write(sphere.toStdString().c_str(),sphere.length());

/* 3D rendered sphere*/
    RPoint ray_origin(0,0,-5);
    RPoint wall(0,0,10);
    const float wall_size=7.0;
    const int canvas_pixels=400;
    const float pixel_size=wall_size/canvas_pixels;
    const float half=wall_size/2;

    RCanvas canvas(canvas_pixels,canvas_pixels);
    RColor color(1,0,0);
    RSphere shape;
    shape.material.color=RColor(1,0.2,1);
    RPointLight light({-10,10,-10},{1,1,1});

    qDebug()<<shape.id;
    for(int y=0;y<canvas_pixels;y++) {
        float world_y=half-pixel_size*y;
        for(int x=0;x<canvas_pixels;x++) {
            float world_x=-half+pixel_size*x;
            RPoint position(world_x,world_y,wall.z);

            RRay r(ray_origin,RVector(position-ray_origin).normalize());

            vector<RIntersection> xs=r.intersect(shape);
            RIntersection tmp=RIntersection::hit(xs);

            if(tmp!=RIntersection()) {
                RPoint point=r.position(tmp.t);
                RSphere& o=*((RSphere*)tmp.obj);
                RVector normal=o.normal_at(point).normalize();
                RVector eye=-r.direction.normalize();
                color=lighting(o.material,light,point,eye,normal);
//                qDebug()<<"Color:"<<color.r<<" "<<color.g<<" "<<color.b;
                canvas.write(x,y,color);
            }
        }
    }
    QString sphere=canvas.to_ppm();
    QFile file("3dsphere.ppm");
    if(!file.open(QIODevice::ReadWrite)) {

    }
    file.write(sphere.toStdString().c_str(),sphere.length());

}

MainWindow::~MainWindow()
{
    delete ui;
}

