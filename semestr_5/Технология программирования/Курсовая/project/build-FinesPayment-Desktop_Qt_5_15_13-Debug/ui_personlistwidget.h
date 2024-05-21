/********************************************************************************
** Form generated from reading UI file 'personlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONLISTWIDGET_H
#define UI_PERSONLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonListWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *leSearch;
    QTableView *tvPersons;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddPerson;
    QPushButton *btnUpdatePerson;
    QPushButton *btnRemovePerson;

    void setupUi(QWidget *PersonListWidget)
    {
        if (PersonListWidget->objectName().isEmpty())
            PersonListWidget->setObjectName(QString::fromUtf8("PersonListWidget"));
        PersonListWidget->resize(952, 787);
        verticalLayout_2 = new QVBoxLayout(PersonListWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        leSearch = new QLineEdit(PersonListWidget);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        verticalLayout->addWidget(leSearch);

        tvPersons = new QTableView(PersonListWidget);
        tvPersons->setObjectName(QString::fromUtf8("tvPersons"));
        tvPersons->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tvPersons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvPersons->setAlternatingRowColors(true);
        tvPersons->setSelectionMode(QAbstractItemView::SingleSelection);
        tvPersons->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvPersons->setSortingEnabled(true);
        tvPersons->horizontalHeader()->setStretchLastSection(true);
        tvPersons->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvPersons);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAddPerson = new QPushButton(PersonListWidget);
        btnAddPerson->setObjectName(QString::fromUtf8("btnAddPerson"));
        btnAddPerson->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnAddPerson);

        btnUpdatePerson = new QPushButton(PersonListWidget);
        btnUpdatePerson->setObjectName(QString::fromUtf8("btnUpdatePerson"));
        btnUpdatePerson->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnUpdatePerson);

        btnRemovePerson = new QPushButton(PersonListWidget);
        btnRemovePerson->setObjectName(QString::fromUtf8("btnRemovePerson"));
        btnRemovePerson->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnRemovePerson);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PersonListWidget);

        QMetaObject::connectSlotsByName(PersonListWidget);
    } // setupUi

    void retranslateUi(QWidget *PersonListWidget)
    {
        PersonListWidget->setWindowTitle(QCoreApplication::translate("PersonListWidget", "Form", nullptr));
        leSearch->setPlaceholderText(QCoreApplication::translate("PersonListWidget", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\275\320\260\321\207\320\260\320\273\320\260 \320\277\320\276\320\270\321\201\320\272\320\260 ...", nullptr));
        btnAddPerson->setText(QCoreApplication::translate("PersonListWidget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnUpdatePerson->setText(QCoreApplication::translate("PersonListWidget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btnRemovePerson->setText(QCoreApplication::translate("PersonListWidget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonListWidget: public Ui_PersonListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONLISTWIDGET_H
