#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T18:40:09
#
#-------------------------------------------------

QT       += core gui
QT += widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = servak
TEMPLATE = app


SOURCES += main.cpp\
        myservak.cpp \
    downloader.cpp

HEADERS  += myservak.h \
    downloader.h
