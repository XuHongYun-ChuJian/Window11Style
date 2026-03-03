QT += svg

HEADERS += \
    $$PWD/cusproxystyle.h \
    $$PWD/customcontrol/dockwidgettitlebar.h \
    $$PWD/qhexstring_p.h \
    $$PWD/qstyleanimation_p.h \
    $$PWD/qstylehelper_p.h

SOURCES += \
    $$PWD/cusproxystyle.cpp \
    $$PWD/customcontrol/dockwidgettitlebar.cpp \
    $$PWD/qstyleanimation.cpp \
    $$PWD/qstylehelper.cpp

RESOURCES += \
    $$PWD/resource.qrc

FORMS += \
    $$PWD/customcontrol/dockwidgettitlebar.ui
