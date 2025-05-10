#include "mymainwindow.h"

#include <QApplication>

// Ctrl+Shift+U
// https://doc.qt.io/qt-5/qapplication.html
// https://doc.qt.io/qt-5/qmainwindow.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.show();
    return a.exec();
}
