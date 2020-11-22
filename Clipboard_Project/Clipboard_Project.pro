QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/databaseops.cpp \
    ../src/loginpage.cpp \
    ../src/main.cpp \
    ../src/mainwindow.cpp \
    ../src/registerdialog.cpp


HEADERS += \
    ../src/databaseops.h \
    ../src/loginpage.h \
    ../src/mainwindow.h \
    ../src/registerdialog.h


FORMS += \
    ../gui/loginpage.ui \
    ../gui/mainwindow.ui \
    ../gui/registerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    my_resources.qrc
