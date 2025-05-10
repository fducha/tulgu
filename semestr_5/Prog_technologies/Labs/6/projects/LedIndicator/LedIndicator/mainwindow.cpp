#include "mainwindow.h"
#include "ledindicator.h"
#include <QHBoxLayout>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QHBoxLayout;
    setLayout(layout);

    auto ledIndicator = new LedIndicator;
    ledIndicator->setText("Светофор");
    layout->addWidget(ledIndicator);

    auto check = new QCheckBox("LED ON");
    layout->addWidget(check);

    connect(check, &QCheckBox::toggled, ledIndicator, &LedIndicator::setTurnedOn);
}

MainWindow::~MainWindow()
{
}

