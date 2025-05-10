QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/messages.cpp \
    common/utils.cpp \
    dbhelper/dbhelper.cpp \
    domain/owner.cpp \
    domain/vehicle.cpp \
    fakes/fakepersongenerator.cpp \
    main.cpp \
    mainwindow.cpp \
    models/ownerfilterproxymodel.cpp \
    models/ownersmodel.cpp \
    repository/abstractrepository.cpp \
    repository/ownerrepository.cpp \
    repository/repos.cpp \
    repository/vehiclerepository.cpp \
    ui/ownereditdialog.cpp

HEADERS += \
    common/messages.h \
    common/utils.h \
    dbhelper/dbhelper.h \
    domain/owner.h \
    domain/vehicle.h \
    fakes/fakepersongenerator.h \
    mainwindow.h \
    models/ownerfilterproxymodel.h \
    models/ownersmodel.h \
    repository/abstractrepository.h \
    repository/ownerrepository.h \
    repository/repos.h \
    repository/vehiclerepository.h \
    ui/ownereditdialog.h

FORMS += \
    mainwindow.ui \
    ui/ownereditdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
