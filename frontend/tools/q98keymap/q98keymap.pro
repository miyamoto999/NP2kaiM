QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inputkeydialog.cpp \
    keydata.cpp \
    keydialog.cpp \
    keywidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    inputkeydialog.h \
    keydata.h \
    keydialog.h \
    keywidget.h \
    mainwindow.h

FORMS += \
    inputkeydialog.ui \
    keydialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    q98keymap.qrc

TRANSLATIONS +=  \
    q98keymap_ja.ts

DISTFILES += \
    q98keymap_js.ts
