#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tuple/rtuple.h"
#include "Canvas/rcanvas.h"
#include "Matrix/rmatrix.h"
#include "Objects/Sphere/rsphere.h"
#include "Ray/rray.h"
#include "Intersection/rintersection.h"
#include "Light/rmaterial.h"
#include "Light/rpointlight.h"
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
