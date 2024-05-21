#include "signalswidget.h"
#include "ui_signalswidget.h"

SignalsWidget::SignalsWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::SignalsWidget)
{
    ui->setupUi(this);

    connect(ui->dial, SIGNAL(sliderMoved(int)), this, SLOT(valueChanged(int)));
    connect(ui->hScroll, SIGNAL(sliderMoved(int)), this, SLOT(valueChanged(int)));
    connect(ui->hSlider, SIGNAL(sliderMoved(int)), this, SLOT(valueChanged(int)));
    connect(ui->vScroll, SIGNAL(sliderMoved(int)), this, SLOT(valueChanged(int)));
    connect(ui->vSlider, SIGNAL(sliderMoved(int)), this, SLOT(valueChanged(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));
}

SignalsWidget::~SignalsWidget()
{
    delete ui;
}

void SignalsWidget::valueChanged(int value) {
    ui->dial->setValue(value);
    ui->hScroll->setValue(value);
    ui->hSlider->setValue(value);
    ui->vScroll->setValue(value);
    ui->vSlider->setValue(value);
    ui->spinBox->setValue(value);
}

