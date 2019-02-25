QT += 3dcore 3drender 3dextras quick  testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase c++11
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    sceneentity.h

SOURCES +=  tst_guitest.cpp \
    sceneentity.cpp

RESOURCES += \
    qml.qrc
