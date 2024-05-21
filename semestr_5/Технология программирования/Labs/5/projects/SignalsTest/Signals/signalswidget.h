#ifndef SIGNALSWIDGET_H
#define SIGNALSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SignalsWidget; }
QT_END_NAMESPACE

class SignalsWidget : public QWidget
{
    Q_OBJECT

public:
    SignalsWidget(QWidget *parent = nullptr);
    ~SignalsWidget();

private slots:
    void valueChanged(int value);
private:
    Ui::SignalsWidget *ui;
};
#endif // SIGNALSWIDGET_H
