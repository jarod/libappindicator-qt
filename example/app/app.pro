#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T16:33:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

QMAKE_CFLAGS += -std=c11
QMAKE_CXXFLAGS += -std=c++11

CONFIG += link_pkgconfig
PKGCONFIG += appindicator-0.1


SOURCES += main.cc\
        mainwindow.cc \
    application.cc

HEADERS  += mainwindow.h \
    application.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../release/ -lappindicator-qt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../debug/ -lappindicator-qt
else:unix: LIBS += -L$$OUT_PWD/../../ -lappindicator-qt

INCLUDEPATH += $$PWD/../../
DEPENDPATH += $$PWD/../../

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../release/libappindicator-qt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../debug/libappindicator-qt.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../release/appindicator-qt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../debug/appindicator-qt.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../libappindicator-qt.a
