#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class IconizedLineEdit;
class QLabel;
class QVBoxLayout;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getFile();

private:
    void loadPicture(const QString &fileName);

    IconizedLineEdit *m_ileFileName;
    QLabel *m_picture;
    QVBoxLayout *m_layout;
};
#endif // MAINWINDOW_H
