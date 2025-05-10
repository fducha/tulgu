#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QWidget>

class QPushButton;
class QLCDNumber;
class QSignalMapper;

class CalculatorMainWindow : public QWidget
{
    Q_OBJECT

public:
    CalculatorMainWindow(QWidget *parent = nullptr);
    ~CalculatorMainWindow();

private slots:
    void clear();
    void btnPressed(int num);
    void plusEqualPressed();

private:
    void createWidgets();

    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPushButton *m_btn2;
    QPushButton *m_btn3;
    QPushButton *m_btn4;
    QPushButton *m_btn5;
    QPushButton *m_btn6;
    QPushButton *m_btn7;
    QPushButton *m_btn8;
    QPushButton *m_btn9;
    QPushButton *m_btnPlus;
    QPushButton *m_btnC;

    QLCDNumber *LCDisplay;

    QSignalMapper *m_mapper;

    int m_sum;
    int m_nextNumber;
};
#endif // CALCULATORMAINWINDOW_H
