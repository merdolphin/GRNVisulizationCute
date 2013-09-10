#-------------------------------------------------
#
# Project created by QtCreator 2013-09-10T13:18:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GRNgui
TEMPLATE = app


SOURCES += main.cpp \
    grncontrolpanel.cpp \
    visulizationwindow.cpp

HEADERS  += \
    grncontrolpanel.h \
    visulizationwindow.h

FORMS    += \
    grncontrolpanel.ui \
    visulizationwindow.ui

OTHER_FILES += \
    style.qss
