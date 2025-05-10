#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class IconizedLineEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectFile();

private:
    void createUi();

    IconizedLineEdit *ilEdit1;
    IconizedLineEdit *ilEdit2;
    IconizedLineEdit *ilEdit3;
    IconizedLineEdit *ilEdit4;
    IconizedLineEdit *ilEdit5;
};
#endif // MAINWINDOW_H
