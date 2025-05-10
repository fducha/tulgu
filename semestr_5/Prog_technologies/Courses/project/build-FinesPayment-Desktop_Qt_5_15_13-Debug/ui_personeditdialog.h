/********************************************************************************
** Form generated from reading UI file 'personeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONEDITDIALOG_H
#define UI_PERSONEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PersonEditDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *leFamilyName;
    QLabel *label_2;
    QLineEdit *leName;
    QLabel *label_3;
    QLineEdit *leSurName;
    QLabel *label_4;
    QDateEdit *deBirthDate;
    QLabel *label_5;
    QLineEdit *lePassport;
    QLabel *label_6;
    QLineEdit *leLicense;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PersonEditDialog)
    {
        if (PersonEditDialog->objectName().isEmpty())
            PersonEditDialog->setObjectName(QString::fromUtf8("PersonEditDialog"));
        PersonEditDialog->resize(405, 478);
        PersonEditDialog->setMinimumSize(QSize(405, 478));
        PersonEditDialog->setMaximumSize(QSize(405, 478));
        horizontalLayout = new QHBoxLayout(PersonEditDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(PersonEditDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        leFamilyName = new QLineEdit(PersonEditDialog);
        leFamilyName->setObjectName(QString::fromUtf8("leFamilyName"));

        verticalLayout->addWidget(leFamilyName);

        label_2 = new QLabel(PersonEditDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        leName = new QLineEdit(PersonEditDialog);
        leName->setObjectName(QString::fromUtf8("leName"));

        verticalLayout->addWidget(leName);

        label_3 = new QLabel(PersonEditDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        leSurName = new QLineEdit(PersonEditDialog);
        leSurName->setObjectName(QString::fromUtf8("leSurName"));

        verticalLayout->addWidget(leSurName);

        label_4 = new QLabel(PersonEditDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        deBirthDate = new QDateEdit(PersonEditDialog);
        deBirthDate->setObjectName(QString::fromUtf8("deBirthDate"));
        deBirthDate->setCalendarPopup(true);

        verticalLayout->addWidget(deBirthDate);

        label_5 = new QLabel(PersonEditDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        lePassport = new QLineEdit(PersonEditDialog);
        lePassport->setObjectName(QString::fromUtf8("lePassport"));

        verticalLayout->addWidget(lePassport);

        label_6 = new QLabel(PersonEditDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        leLicense = new QLineEdit(PersonEditDialog);
        leLicense->setObjectName(QString::fromUtf8("leLicense"));

        verticalLayout->addWidget(leLicense);

        line = new QFrame(PersonEditDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(PersonEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout);

#if QT_CONFIG(shortcut)
        label->setBuddy(leFamilyName);
        label_2->setBuddy(leName);
        label_3->setBuddy(leSurName);
        label_4->setBuddy(deBirthDate);
        label_5->setBuddy(lePassport);
        label_6->setBuddy(leLicense);
#endif // QT_CONFIG(shortcut)

        retranslateUi(PersonEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PersonEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PersonEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PersonEditDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonEditDialog)
    {
        PersonEditDialog->setWindowTitle(QCoreApplication::translate("PersonEditDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PersonEditDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("PersonEditDialog", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("PersonEditDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("PersonEditDialog", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        deBirthDate->setSpecialValueText(QCoreApplication::translate("PersonEditDialog", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("PersonEditDialog", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        lePassport->setInputMask(QCoreApplication::translate("PersonEditDialog", "99 99 999999", nullptr));
        label_6->setText(QCoreApplication::translate("PersonEditDialog", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214\321\201\320\272\320\276\320\265 \321\203\320\264\320\276\321\201\321\202\320\262\320\265\321\200\320\265\320\275\320\270\320\265", nullptr));
        leLicense->setInputMask(QCoreApplication::translate("PersonEditDialog", "99 >NN 999999", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonEditDialog: public Ui_PersonEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONEDITDIALOG_H
