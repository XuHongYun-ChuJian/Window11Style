QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

win32-msvc {
    QMAKE_CXXFLAGS += /utf-8
}

RC_ICONS = appicon.ico

SOURCES += \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/fluentui3style
include($$PWD/fluentui3style/fluentui3style.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
