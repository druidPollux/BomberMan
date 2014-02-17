#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T11:28:54
#
#-------------------------------------------------

QT       += core gui
QT += widgets
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    windowstatistics.cpp

HEADERS  += mainwindow.h \
    windowstatistics.h

FORMS    += mainwindow.ui \
    windowstatistics.ui
