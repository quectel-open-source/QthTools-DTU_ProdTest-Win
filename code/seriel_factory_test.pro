QT       += core gui
QT       += serialport
QT       += axcontainer
QT       += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include ($$PWD/third/QSimpleUpdater/QSimpleUpdater.pri)
CONFIG += c++11
RC_FILE += image/quectel.rc
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    serial.cpp

HEADERS += \
    mainwindow.h \
    serial.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    image/quectel.ico \
    image/quectel.rc
