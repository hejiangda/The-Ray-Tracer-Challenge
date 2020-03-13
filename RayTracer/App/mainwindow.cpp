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
    RCanvas clock(400,400);
    RColor white(1,1,1);
    clock.write(200,200,white);
    RPoint p(0,1,0);

    for(int i=0;i<12;i++) {
        RMatrix4 rotScal;
        rotScal.translation(200,200,0).scale(150,150,0).rotation_z((M_PI*i)/6);
        RPoint tmp=rotScal*p;
        clock.write(tmp.x,tmp.y,white);
        qDebug()<<tmp.x<<" "<<tmp.y;
    }
    QString clockPpm=clock.to_ppm();
    QFile file("clock.ppm");
    if(!file.open(QIODevice::ReadWrite)) {

    }
    file.write(clockPpm.toStdString().c_str(),clockPpm.length());
}

MainWindow::~MainWindow()
{
    delete ui;
}

