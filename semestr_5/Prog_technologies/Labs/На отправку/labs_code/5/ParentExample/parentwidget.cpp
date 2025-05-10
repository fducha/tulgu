#include "parentwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

ParentWidget::ParentWidget(QWidget *parent)
    : QWidget{parent}
{
    auto label = new QLabel(this);
    label->setGeometry(50,0,100,30);
    label->setText("Текст метки");
    auto button = new QPushButton(this);
    button->setGeometry(50,50,100,30);
    button->setText("Кнопочка");
    auto lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(50,100,100,30);
    lineEdit->setText("Поле ввода текста");
    lineEdit->selectAll();
    setGeometry(x(), y(), 300, 150);
    setWindowTitle("Пример родительского виджета");
}
