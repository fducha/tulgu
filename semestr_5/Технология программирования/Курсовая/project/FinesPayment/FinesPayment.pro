QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/messages.cpp \
    dbhelper/dbhelper.cpp \
    domain/person.cpp \
    fakes/fakepersongenerator.cpp \
    main.cpp \
    mainwindow.cpp \
    models/personfilterproxymodel.cpp \
    models/personsmodel.cpp \
    repository/abstractrepository.cpp \
    repository/personrepository.cpp \
    repository/repos.cpp \
    ui/personeditdialog.cpp \
    ui/personlistwidget.cpp

HEADERS += \
    common/messages.h \
    dbhelper/dbhelper.h \
    domain/person.h \
    fakes/fakepersongenerator.h \
    mainwindow.h \
    models/personfilterproxymodel.h \
    models/personsmodel.h \
    repository/abstractrepository.h \
    repository/personrepository.h \
    repository/repos.h \
    ui/personeditdialog.h \
    ui/personlistwidget.h

FORMS += \
    mainwindow.ui \
    ui/personeditdialog.ui \
    ui/personlistwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
