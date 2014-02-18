#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T11:28:54
#
#-------------------------------------------------

QT       += core gui
#---- Partie Modifié le 30/01/2014
QT += widgets
QT += network
#---- Fin modif
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        windowstatistics.cpp \
    paramwindows.cpp \
    windowserveur.cpp \
    launchsologame.cpp

HEADERS += mainwindow.h \
        windowstatistics.h \
    paramwindows.h \
    windowserveur.h \
    launchsologame.h

FORMS    += mainwindow.ui \
    windowstatistics.ui \
    paramwindows.ui \
    windowserveur.ui \
    launchsologame.ui
