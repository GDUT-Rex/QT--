#-------------------------------------------------
#
# Project created by QtCreator 2018-06-18T15:13:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    login2.cpp \
    navigation.cpp \
    mainmenu.cpp \
    search.cpp \
    graph.cpp \
    adddata.cpp \
    addroad.cpp \
    addpoint.cpp \
    deletroad.cpp \
    modify_point.cpp

HEADERS  += \
    login2.h \
    navigation.h \
    mainmenu.h \
    search.h \
    graph.h \
    adddata.h \
    addroad.h \
    addpoint.h \
    deletroad.h \
    modify_point.h

FORMS    += \
    login2.ui \
    navigation.ui \
    mainmenu.ui \
    search.ui \
    adddata.ui \
    addroad.ui \
    addpoint.ui \
    deletroad.ui \
    modify_point.ui

DISTFILES +=
