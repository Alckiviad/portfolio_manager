QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=../external/QXlsx
QXLSX_HEADERPATH=../external/QXlsx/QXlsx/header/
QXLSX_SOURCEPATH=../external/QXlsx/QXlsx/source/
include(../external/QXlsx/QXlsx/QXlsx.pri)

SOURCES += \
#    ../components/interactiondb/interactiondb.cpp \
    ../components/broker_reports/broker_reports.cpp \
    ../components/broker_reports/pmassets.cpp \
    ../components/broker_reports/pmmoney.cpp \
    ../components/broker_reports/pmtransaction.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
#    ../components/interactiondb/interactiondb.h \
    ../components/broker_reports/broker_reports.h \
    ../components/broker_reports/pmassets.h \
    ../components/broker_reports/pmmoney.h \
    ../components/broker_reports/pmtransaction.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
