/********************************************************************************
** Form generated from reading UI file 'signalswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALSWIDGET_H
#define UI_SIGNALSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalsWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QScrollBar *hScroll;
    QSlider *hSlider;
    QDial *dial;
    QSpinBox *spinBox;
    QScrollBar *vScroll;
    QSlider *vSlider;

    void setupUi(QWidget *SignalsWidget)
    {
        if (SignalsWidget->objectName().isEmpty())
            SignalsWidget->setObjectName(QString::fromUtf8("SignalsWidget"));
        SignalsWidget->resize(428, 432);
        horizontalLayout_2 = new QHBoxLayout(SignalsWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hLayout = new QHBoxLayout();
        hLayout->setObjectName(QString::fromUtf8("hLayout"));
        vLayout = new QVBoxLayout();
        vLayout->setObjectName(QString::fromUtf8("vLayout"));
        hScroll = new QScrollBar(SignalsWidget);
        hScroll->setObjectName(QString::fromUtf8("hScroll"));
        hScroll->setOrientation(Qt::Horizontal);

        vLayout->addWidget(hScroll);

        hSlider = new QSlider(SignalsWidget);
        hSlider->setObjectName(QString::fromUtf8("hSlider"));
        hSlider->setOrientation(Qt::Horizontal);

        vLayout->addWidget(hSlider);

        dial = new QDial(SignalsWidget);
        dial->setObjectName(QString::fromUtf8("dial"));

        vLayout->addWidget(dial);

        spinBox = new QSpinBox(SignalsWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        vLayout->addWidget(spinBox);


        hLayout->addLayout(vLayout);

        vScroll = new QScrollBar(SignalsWidget);
        vScroll->setObjectName(QString::fromUtf8("vScroll"));
        vScroll->setOrientation(Qt::Vertical);

        hLayout->addWidget(vScroll);

        vSlider = new QSlider(SignalsWidget);
        vSlider->setObjectName(QString::fromUtf8("vSlider"));
        vSlider->setOrientation(Qt::Vertical);

        hLayout->addWidget(vSlider);


        horizontalLayout_2->addLayout(hLayout);


        retranslateUi(SignalsWidget);

        QMetaObject::connectSlotsByName(SignalsWidget);
    } // setupUi

    void retranslateUi(QWidget *SignalsWidget)
    {
        SignalsWidget->setWindowTitle(QCoreApplication::translate("SignalsWidget", "SignalsWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignalsWidget: public Ui_SignalsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALSWIDGET_H
