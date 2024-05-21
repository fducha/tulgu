#include "mainwindow.h"
#include "ledindicator.h"
#include <QBoxLayout>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QHBoxLayout;

    auto ledIndicator = new LedIndicator;
    ledIndicator->setMinimumHeight(50);
    ledIndicator->setText("Светофор");
    layout->addWidget(ledIndicator);

    m_check = new QCheckBox("LED ON");
    layout->addWidget(m_check);

    m_checkMiddle = new QCheckBox("SET MIDDLE");

    auto vlayout = new QVBoxLayout;
    setLayout(vlayout);
    vlayout->addLayout(layout);
    vlayout->addWidget(m_checkMiddle);

    connect(m_check, &QCheckBox::toggled, ledIndicator, &LedIndicator::setTurnedOn);
    connect(m_checkMiddle, &QCheckBox::toggled, ledIndicator, &LedIndicator::setTristate);
    connect(m_checkMiddle, &QCheckBox::toggled, this, &MainWindow::unchecked);
}

MainWindow::~MainWindow()
{
    delete m_check;
    delete m_checkMiddle;
}

void MainWindow::unchecked() {
    if (!m_checkMiddle->isChecked()) m_check->setChecked(false);
}

