#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class QCheckBox;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void unchecked();

private:
    QCheckBox *m_check;
    QCheckBox *m_checkMiddle;
};
#endif // MAINWINDOW_H
