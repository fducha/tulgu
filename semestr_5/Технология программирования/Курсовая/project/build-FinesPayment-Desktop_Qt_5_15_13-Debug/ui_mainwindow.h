/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ui/personlistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *twMain;
    QWidget *tabCrimes;
    QWidget *tabVehicles;
    QWidget *tabPersons;
    QHBoxLayout *horizontalLayout_2;
    PersonListWidget *wtPersons;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCloseApp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1168, 965);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        twMain = new QTabWidget(centralwidget);
        twMain->setObjectName(QString::fromUtf8("twMain"));
        twMain->setTabShape(QTabWidget::Rounded);
        tabCrimes = new QWidget();
        tabCrimes->setObjectName(QString::fromUtf8("tabCrimes"));
        twMain->addTab(tabCrimes, QString());
        tabVehicles = new QWidget();
        tabVehicles->setObjectName(QString::fromUtf8("tabVehicles"));
        twMain->addTab(tabVehicles, QString());
        tabPersons = new QWidget();
        tabPersons->setObjectName(QString::fromUtf8("tabPersons"));
        horizontalLayout_2 = new QHBoxLayout(tabPersons);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wtPersons = new PersonListWidget(tabPersons);
        wtPersons->setObjectName(QString::fromUtf8("wtPersons"));

        horizontalLayout_2->addWidget(wtPersons);

        twMain->addTab(tabPersons, QString());

        verticalLayout->addWidget(twMain);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(998, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCloseApp = new QPushButton(centralwidget);
        btnCloseApp->setObjectName(QString::fromUtf8("btnCloseApp"));

        horizontalLayout->addWidget(btnCloseApp);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(btnCloseApp, SIGNAL(clicked()), MainWindow, SLOT(close()));

        twMain->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        twMain->setTabText(twMain->indexOf(tabCrimes), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\276\320\275\320\260\321\200\321\203\321\210\320\265\320\275\320\270\321\217", nullptr));
        twMain->setTabText(twMain->indexOf(tabVehicles), QCoreApplication::translate("MainWindow", " \320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", nullptr));
        twMain->setTabText(twMain->indexOf(tabPersons), QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\270\320\272\320\270 \320\242\320\241", nullptr));
        btnCloseApp->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
