include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../App/Tuple/rtuple.h \
        UnitTest.h

SOURCES += \
        UnitTest.cpp \
        main.cpp \
        ../App/Tuple/rtuple.cpp

