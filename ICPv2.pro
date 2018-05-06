#-------------------------------------------------
#
# Project created by QtCreator 2018-04-29T17:03:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ICPv2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    connection.cpp \
    block.cpp \
    board.cpp \
    port.cpp \
    qblock.cpp \
    modal.cpp

HEADERS  += widget.h \
    connection.h \
    block.h \
    board.h \
    port.h \
    qblock.h \
    modal.h

FORMS    += widget.ui \
    modal.ui

RESOURCES += \
    res.qrc

CONFIG += c++14
