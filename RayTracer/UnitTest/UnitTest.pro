include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        UnitTest.h \

SOURCES += \
        CanvasTest.cpp \
        IntersectionsTest.cpp \
        MatrixTest.cpp \
        MatrixTransformationTest.cpp \
        RaysTest.cpp \
        SpheresTest.cpp \
        TupleTest.cpp \
        main.cpp \
        ../App/Tuple/rtuple.cpp \
        ../App/Canvas/rcanvas.cpp \
        ../App/Matrix/rmatrix.cpp \
        ../App/Ray/rray.cpp \
        ../App/Objects/robject.cpp \
        ../App/Objects/Sphere/rsphere.cpp \
        ../App/Intersection/rintersection.cpp

INCLUDEPATH += ../App
DEPENDPATH += ../App

#QMAKE_CXXFLAGS += --coverage
#QMAKE_LFLAGS +=  --coverage
