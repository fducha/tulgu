#include "calculatormainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QSignalMapper>

CalculatorMainWindow::CalculatorMainWindow(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 300);
    setWindowTitle("Простой калькулятор");
    createWidgets();

    connect(m_btnC, &QPushButton::clicked,
            this, &CalculatorMainWindow::clear, Qt::UniqueConnection);
    connect(m_btnPlus, &QPushButton::clicked,
            this, &CalculatorMainWindow::plusEqualPressed, Qt::UniqueConnection);

    m_mapper = new QSignalMapper(this);
    connect(m_btn0, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn1, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn2, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn3, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn4, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn5, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn6, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn7, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn8, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);
    connect(m_btn9, SIGNAL(clicked()), m_mapper, SLOT(map()), Qt::UniqueConnection);

    m_mapper->setMapping(m_btn0, 0);
    m_mapper->setMapping(m_btn1, 1);
    m_mapper->setMapping(m_btn2, 2);
    m_mapper->setMapping(m_btn3, 3);
    m_mapper->setMapping(m_btn4, 4);
    m_mapper->setMapping(m_btn5, 5);
    m_mapper->setMapping(m_btn6, 6);
    m_mapper->setMapping(m_btn7, 7);
    m_mapper->setMapping(m_btn8, 8);
    m_mapper->setMapping(m_btn9, 9);

    clear();

    connect(m_mapper, SIGNAL(mapped(int)), this, SLOT(btnPressed(int)), Qt::UniqueConnection);
}

CalculatorMainWindow::~CalculatorMainWindow()
{
}

void CalculatorMainWindow::clear() {
    LCDisplay->display(0);
    m_sum = 0;
    m_nextNumber = 0;
}

void CalculatorMainWindow::btnPressed(int num) {
    m_nextNumber = num;
    LCDisplay->display(num);
}

void CalculatorMainWindow::plusEqualPressed() {
    m_sum += m_nextNumber;
    LCDisplay->display(m_sum);
    m_nextNumber = 0;
}

void CalculatorMainWindow::createWidgets() {
    auto lytCalc = new QGridLayout;
    setLayout(lytCalc);

    LCDisplay = new QLCDNumber;

    m_btn0 = new QPushButton(" 0 ");
    m_btn1 = new QPushButton(" 1 ");
    m_btn2 = new QPushButton(" 2 ");
    m_btn3 = new QPushButton(" 3 ");
    m_btn4 = new QPushButton(" 4 ");
    m_btn5 = new QPushButton(" 5 ");
    m_btn6 = new QPushButton(" 6 ");
    m_btn7 = new QPushButton(" 7 ");
    m_btn8 = new QPushButton(" 8 ");
    m_btn9 = new QPushButton(" 9 ");
    m_btnPlus = new QPushButton(" +/= ");
    m_btnC = new QPushButton(" C ");

    lytCalc->addWidget(LCDisplay, 0, 0, 1, 4);
    lytCalc->addWidget(m_btn1, 1, 0);
    lytCalc->addWidget(m_btn2, 1, 1);
    lytCalc->addWidget(m_btn3, 1, 2);
    lytCalc->addWidget(m_btn4, 2, 0);
    lytCalc->addWidget(m_btn5, 2, 1);
    lytCalc->addWidget(m_btn6, 2, 2);
    lytCalc->addWidget(m_btn7, 3, 0);
    lytCalc->addWidget(m_btn8, 3, 1);
    lytCalc->addWidget(m_btn9, 3, 2);
    lytCalc->addWidget(m_btn0, 4, 0, 1, 3);
    lytCalc->addWidget(m_btnC, 1, 3);
    lytCalc->addWidget(m_btnPlus, 2, 3, 3, 1);

    m_btn0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btn9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btnPlus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_btnC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    LCDisplay->setFixedHeight(50);
}

