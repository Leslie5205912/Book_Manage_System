#-------------------------------------------------
#
# Project created by QtCreator 2018-11-16T11:51:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Book_management_system
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    book_student.cpp \
    book_administrator.cpp \
    book_super_administrator.cpp \
    reserve.cpp \
    book_borrow.cpp \
    insert.cpp \
    choose.cpp \
    book_delete.cpp \
    admini_delete.cpp \
    adimi_insert.cpp \
    stu_delete.cpp \
    stu_insert.cpp

HEADERS += \
        mainwindow.h \
    book_student.h \
    book_administrator.h \
    book_super_administrator.h \
    reserve.h \
    book_borrow.h \
    insert.h \
    choose.h \
    book_delete.h \
    admini_delete.h \
    adimi_insert.h \
    stu_delete.h \
    stu_insert.h

FORMS += \
        mainwindow.ui \
    book_student.ui \
    book_administrator.ui \
    book_super_administrator.ui \
    reserve.ui \
    book_borrow.ui \
    insert.ui \
    choose.ui \
    book_delete.ui \
    admini_delete.ui \
    adimi_insert.ui \
    stu_delete.ui \
    stu_insert.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
