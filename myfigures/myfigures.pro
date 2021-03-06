#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T15:40:09
#
#-------------------------------------------------

QT       += core gui opengl sql
LIBS += -lGLU




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myfigures
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myopenglwidget.cpp \
    figure.cpp \
    sphere.cpp \
    camera.cpp \
    quadrangularpyramid.cpp \
    toolbar.cpp \
    addshapedialog.cpp \
    editpyramiddialog.cpp \
    editspheredialog.cpp \
    database.cpp \
    editscenedialog.cpp \
    chosescenedialog.cpp \
    loadscenedialog.cpp \
    ellipse.cpp

HEADERS += \
        mainwindow.h \
    myopenglwidget.h \
    figure.h \
    sphere.h \
    camera.h \
    quadrangularpyramid.h \
    toolbar.h \
    addshapedialog.h \
    editpyramiddialog.h \
    editspheredialog.h \
    database.h \
    editscenedialog.h \
    chosescenedialog.h \
    loadscenedialog.h \
    ellipse.h

FORMS += \
        mainwindow.ui \
    addshapedialog.ui \
    editpyramiddialog.ui \
    editspheresdialog.ui \
    editscenedialog.ui \
    chosescenedialog.ui \
    loadscenedialog.ui

DISTFILES +=

RESOURCES += \
    images.qrc \
    database.qrc
