#-------------------------------------------------
#
# Project created by QtCreator 2018-02-18T14:18:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myapp
TEMPLATE = app


SOURCES += main.cpp\
    finance.cpp \
        mainwindow.cpp \
    worker.cpp \
    register.cpp \
    findpassword.cpp \
    workermodifydialog.cpp \
    resources.cpp \
    manager.cpp \
    managerdialog.cpp \
    addworker.cpp \
    modifypassword.cpp \
    databackup.cpp \
    displayworker.cpp \
    analys.cpp \
    displaybydepartment.cpp \
    datarecovery.cpp

HEADERS  += mainwindow.h \
    finance.h \
    macro.h \
    param.h \
    stdafx.h \
    worker.h \
    register.h \
    findpassword.h \
    workermodifydialog.h \
    resources.h \
    manager.h \
    managerdialog.h \
    addworker.h \
    modifypassword.h \
    databackup.h \
    displayworker.h \
    analys.h \
    displaybydepartment.h \
    datarecovery.h

FORMS    += mainwindow.ui \
    finance.ui \
    register.ui \
    findpassword.ui \
    workermodifydialog.ui \
    managerdialog.ui \
    addworker.ui \
    modifypassword.ui \
    databackup.ui \
    displayworker.ui \
    analys.ui \
    displaybydepartment.ui \
    datarecovery.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
