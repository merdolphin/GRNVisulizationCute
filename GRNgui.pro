#-------------------------------------------------
#
# Project created by QtCreator 2013-09-10T13:18:51
# Copyright lina <lina.oahz@gmail.com>
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GRNgui
TEMPLATE = app

CONFIG += console \
    link_pkgconfig

PKGCONFIG += libgvc

SOURCES += main.cpp \
    grncontrolpanel.cpp \
    visulizationwindow.cpp \
    dataprocessing.cpp

HEADERS  += \
    grncontrolpanel.h \
    visulizationwindow.h \
    dataprocessing.h

FORMS    += \
    grncontrolpanel.ui \
    visulizationwindow.ui

OTHER_FILES += \
    style.qss
