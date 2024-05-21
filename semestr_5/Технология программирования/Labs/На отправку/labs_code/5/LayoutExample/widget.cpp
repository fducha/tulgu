#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto lineEdit = new QLineEdit("Text 1");
    auto label = new QLabel("Line Edit &1");
    label->setBuddy(lineEdit);
    auto hbLayout = new QHBoxLayout;
    hbLayout->addWidget(label);
    hbLayout->addWidget(lineEdit);

    auto lineEdit2 = new QLineEdit("Text 2");
    auto label2 = new QLabel("Line Edit &2");
    label2->setBuddy(lineEdit2);
    auto hbLayout2 = new QHBoxLayout;
    hbLayout2->addWidget(label2);
    hbLayout2->addWidget(lineEdit2);

    auto btnOK = new QPushButton("&OK");
    auto btnCancel = new QPushButton("&Cancel");
    auto hbLayout3 = new QHBoxLayout;

    hbLayout3->addStretch();
    hbLayout3->addWidget(btnOK);
    hbLayout3->addWidget(btnCancel);

    auto vbLayout = new QVBoxLayout;
    vbLayout->addLayout(hbLayout);
    vbLayout->addLayout(hbLayout2);
    vbLayout->addLayout(hbLayout3);

    setLayout(vbLayout);
}

Widget::~Widget()
{
}

