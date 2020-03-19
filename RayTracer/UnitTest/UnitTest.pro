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
        MatrixTest.cpp \
        MatrixTransformationTest.cpp \
        RaysTest.cpp \
        SpheresTest.cpp \
        TupleTest.cpp \
        main.cpp \
        ../App/Tuple/rtuple.cpp \
        ../App/Canvas/rcanvas.cpp \
        ../App/Matrix/rmatrix.cpp \
        ../App/Ray/rray.cpp

INCLUDEPATH += ../App
QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS +=  --coverage
