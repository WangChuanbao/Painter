#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T17:05:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = panter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formone.cpp \
    formtwo.cpp \
    formthree.cpp \
    formimage.cpp \
    formfive.cpp

HEADERS  += mainwindow.h \
    formone.h \
    formtwo.h \
    formthree.h \
    formimage.h \
    formfive.h

FORMS    += mainwindow.ui \
    formone.ui \
    formtwo.ui \
    formthree.ui \
    formimage.ui \
    formfive.ui

RESOURCES += \
    myresources.qrc
