include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../App/rtuple.h \
        ch01Test.h

SOURCES += \
        ch01Test.cpp \
        main.cpp \
        ../App/rtuple.cpp

