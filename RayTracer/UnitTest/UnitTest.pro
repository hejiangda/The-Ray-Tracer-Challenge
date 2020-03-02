include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_tuples.h \
        ../App/rtuple.h

SOURCES += \
        ch01Test.cpp \
        main.cpp \
        ../App/rtuple.cpp

