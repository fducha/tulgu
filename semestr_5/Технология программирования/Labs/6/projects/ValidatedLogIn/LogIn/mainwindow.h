#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QPushButton;
class IconizedLineEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createUi();

private slots:
    void onValidate();
    void logined();

private:
    IconizedLineEdit *m_ileLogin;
    IconizedLineEdit *m_ilePassword;
    QPushButton *m_btnLogin;
    QPushButton *m_btnClose;
};
#endif // MAINWINDOW_H
