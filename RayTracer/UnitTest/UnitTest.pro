include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../App/Tuple/rtuple.h \
        UnitTest.h \
        ../App/Canvas/rcanvas.h

SOURCES += \
        CanvasTest.cpp \
        TupleTest.cpp \
        main.cpp \
        ../App/Tuple/rtuple.cpp \
        ../App/Canvas/rcanvas.cpp

