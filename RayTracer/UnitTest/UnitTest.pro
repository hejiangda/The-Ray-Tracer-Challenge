include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        ../App/Tuple/rtuple.h \
        UnitTest.h \
        ../App/Canvas/rcanvas.h \
        ../App/Matrix/rmatrix.h

SOURCES += \
        CanvasTest.cpp \
        MatrixTest.cpp \
        MatrixTransformationTest.cpp \
        TupleTest.cpp \
        main.cpp \
        ../App/Tuple/rtuple.cpp \
        ../App/Canvas/rcanvas.cpp \
        ../App/Matrix/rmatrix.cpp

