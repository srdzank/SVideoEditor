QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Gui/BottomComponents/component_item.cpp \
    Gui/BottomComponents/sbottomcomponet.cpp \
    Gui/BottomListTracks/savcomponent.cpp \
    Gui/BottomListTracks/sspancomponent.cpp \
    Gui/Main/scomponent.cpp \
    XML/ccustomxml.cpp \
    XML/cxmlhelper.cpp \
    CollaborationHub/cbottomsubject.cpp \
    cframeclass.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Gui/BottomComponents/component_item.h \
    Gui/BottomComponents/sbottomcomponet.h \
    Gui/BottomListTracks/savcomponent.h \
    Gui/BottomListTracks/sspancomponent.h \
    Gui/Main/scomponent.h \
    XML/ccustomxml.h \
    XML/cxmlhelper.h \
    CollaborationHub/cbottomsubject.h \
    cframeclass.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
