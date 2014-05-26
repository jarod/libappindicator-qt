#-------------------------------------------------
#
# Project created by QtCreator 2014-05-23T16:50:34
#
#-------------------------------------------------

QT       -= gui

TARGET = appindicator-qt
TEMPLATE = lib

CONFIG += staticlib

SOURCES += qappindicator.cc

HEADERS += qappindicator.h

unix {
	CONFIG += link_pkgconfig
	PKGCONFIG += appindicator-0.1

    target.path = /usr/lib
    INSTALLS += target
}
